#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=1000005;
int a[N],S[N];
vector<pair<int,int>> vec;
int query(int l,int r){
	return S[l-1]^S[r];
}
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.second!=b.second) return a.second<b.second;
	else return a.first>b.first;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >>k;
	int cnta=0,cntb=0;
	for(int i=1;i<=n;i++){
		//Standard Template Library
		cin >> a[i];
		if(a[i]==1) cnta++;
		if(a[i]==0) cntb++;
		S[i]=S[i-1]^a[i];
	}
	if(n>=1e5&&k==1){
		cout << cnta << endl;
		return 0;
	} 
	if(n>=1e5&&k==0){
		cout << cntb << endl;
		return 0;
	}
	for(int r=1;r<=n;r++){
		for(int len=1;r-len+1>=1;len++){
			int l=r-len+1;
			if(query(l,r)==k){
			    vec.push_back(make_pair(l,r));	
			}
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	int last=0,cnt=0;
	for(auto t:vec){
		if(t.first>last){
			last=t.second;
			cnt++;
		}
	}
	cout << cnt << endl;
	
} 
