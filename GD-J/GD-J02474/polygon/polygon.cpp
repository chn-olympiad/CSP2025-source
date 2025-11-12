#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int d[5005];
int f[5005][5005];
const int mod=998244353;
ll dfs(int m,int k,ll sum,int maxn){
	if(m>=n||k>=n) return 0;
	if(f[m][k]&&k>=3) return f[m][k];
	long long s1=( dfs( m+1 , k+1 , sum+d[m] , max(maxn,d[m]) )%mod + ( ( sum + d[m] > 2*max(maxn,d[m]) ) && k>=3 ) ) %mod;
	long long s2=( dfs( m+1 , k , sum , maxn )%mod + ( ( sum > 2*maxn ) && k>=3 ) ) %mod;
	f[m][k]=(s1+s2)%mod;
	return f[m][k];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		int s=d[0]+d[1]+d[2];
		int p=max({d[0],d[1],d[2]});
		if(s>2*p) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==4){
		int c1=d[0]+d[1]+d[2];
		int c2=d[3]+d[0]+d[2];
		int c3=d[1]+d[2]+d[3];
		int v1=max({d[1],d[2],d[3]});
		int v2=max({d[0],d[2],d[3]});
		int v3=max({d[1],d[2],d[0]});
		int cnt=0;
		if(c1>2*v1) cnt++;
		if(c3>2*v3) cnt++;
		if(c2>2*v2) cnt++;
		cout<<cnt;
		return 0;
	}
	cout<<(dfs(0,0,0,0))%mod;
	return 0;
}





























