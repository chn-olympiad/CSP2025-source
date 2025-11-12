#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int N=5e5+5,A=1.1e6;

int n;
int a[N],t[N],p[N];
vector<int>x[A];

void update(int x,int k){
	for(int i=x;i<=n;i+=i&-i){
		t[i]^=k;
	}
}

int pre(int x){
	int ret=0;
	for(int i=x;i>=1;i-=i&-i){
		ret^=t[i];
	}
	return ret;
}

bool cmp(pair<int,int>a,pair<int,int>b){
	if(a.second==b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef local
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
	#endif
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]);
	}
	for(int i=1;i<=n;i++){
		p[i]=pre(i);
	}
	vector<pair<int,int>>f;
	for(int i=0;i<=n;i++){
		x[p[i]].push_back(i);
	}
	for(int r=1;r<=n;r++){
		int pl=p[r]^k;
		if(x[pl].empty()){
			continue;
		}
		int pos=upper_bound(x[pl].begin(),x[pl].end(),r-1)-x[pl].begin()-1;
		if(pos>=0){
			int l=x[pl][pos]+1;
			f.push_back({l,r});
		}
	}
	sort(f.begin(),f.end(),cmp);
	int now=0,sum=0,len=f.size();
	for(int i=0;i<len;i++){
		if(f[i].first>now){
			now=f[i].second;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

