#include<bits/stdc++.h>
using namespace std;
using int64=long long;
const int64 MOD=998244353LL;
int64 n,ans=0,maxx=0;vector<int64>arr(5000);
void dfs(int64 xx,int64 maxx,int64 h){
	if(xx>=n){
		if(h<=2*maxx)return;
		ans++;return;
	}
	dfs(xx+1,maxx,h);
	dfs(xx+1,max(maxx,arr[xx]),h+arr[xx]);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int64 i=0;i<n;i++)cin>>arr[i],maxx=max(maxx,arr[i]);
	if(maxx==1){
		cout<<(n*n*n-3*n*n+2*n)/6%MOD;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans%MOD;
	return 0;
}