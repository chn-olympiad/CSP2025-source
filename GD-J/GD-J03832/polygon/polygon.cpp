#include<bits/stdc++.h>
using namespace std;
void inti(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
const int mod=998244353;
int n;
int cnt;
int a[5001];
bool A=true;
int cnta,cntb;
void dfs(int i,int sum,int mx){
	if(i>n){
		cnt+=(sum>2*mx);
		cnt%=mod;
		return;
	}
	dfs(i+1,sum+a[i],max(mx,a[i]));
	dfs(i+1,sum,mx);
}
signed main(){
	inti();
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>1){
			A=false;
		}
	}
	dfs(1,0,0);
	cout<<cnt;
	return 0;
}
