#include <bits/stdc++.h>
using namespace std;

#define flag cout<<"!!! ";

typedef pair<int,int> pii;

const int N = 5e5+7;

int a[N];

vector<pii> anses;
vector<int>suf;

bool biao[N];

int find(int x){
	int l=0,r=suf.size()-1;
	while(l<=r){
		int mid = l+(r-l)/2;
		if(a[mid]>x)r=mid-1;
		if(a[mid]<x)l=mid+1;
		else return mid;
	}
	return -1;
}

int n,k;

bool cmp(const pii &x,const pii &y){
	if(x.first == y.first)return x.second < y.second;
	else return x.first < y.first;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	
	
	
	for(int i=0;i<n;++i){
		int x;
		cin >> x;
		a[i] = x;
		
	}
	/*
	suf.push_back(a[0]);
	for(int i=1;i<n;++i){
		suf.push_back(suf[i-1] ^ a[i]);
	}
	
	for(int i=0;i<n;++i){
		int need = k ^ suf[i];
		auto x = lower_bound(suf.begin(),suf.end(),need);
		if(x==suf.end())continue;
		cout<<i<<" "<<x-suf.begin()<<endl;
		anses.push_back({i,*x});
	}*/
	/*
	if(maxn==1 && k==1 && 0){
		/*
		int ans=0;
		bool x=0,y=0;
		for(int i=0;i<n;++i){
			
			if(a[i] == 0 ){
				if(y) {
					++ans;
					y=0;
				}
				else x=1;
			}
			if(a[i] == 1){
				if(x) {
					++ans;
					x=0;
				}
				else y=1;
			}
		}
		cout<<ans;
		return 0;
		
		
		int x=0,ans=0;
		for(int i=0;i<n;++i){
			if(x!=a[i]){
				x=a[i];
				++ans;
			}
		}
		cout<<ans;
		return 0;
	}
	*/
	
	
	for(int l1=0;l1<n;++l1){
		int ans = 0;
		for(int x=l1;x<n;++x){
			ans ^= a[x];
			if(ans == k){
				anses.push_back({l1,x});
			}
		}
	}
	
	
	sort(anses.begin(),anses.end(),cmp);
	
	
	
	long long bebiaoed = 0;
	
	for(int i=0;i<(int)anses.size();++i){
		for(int j=i+1;j<(int)anses.size();++j){
			pii &t=anses[i],u=anses[j];
			if(biao[i]||biao[j]){
				continue;
			}
			
			if(t.second >= u.first){
				if(t.second < u.second)biao[j]=1;
				else biao[i]=1;
				bebiaoed++;
			}
		}
	}
	/*
	for(int i=0;i<(int)anses.size();++i){
		
		cout<<anses[i].first<<" "<<anses[i].second<<" "<<biao[i]<<endl;
	}*/
	
	cout<<anses.size() - bebiaoed;
	
	return 0;
}
