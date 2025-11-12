#include<bits/stdc++.h>
#define ll long long
#define MAXN 505
#define MAXM 505
#define mod 998244353
using namespace std;
int n,m,special=1;
int s[MAXN],c[MAXN],st[MAXN];
ll ans;
bool flag[MAXN];
bool check(){
	int giveup=0,sum=0;
	for(int i=1;i<=n;++i)
		if(!s[i])
			giveup++;
		else if(giveup>=c[st[i]])
			giveup++;
		else
			sum++;
	return sum>=m;
}
void dfs(int k){
	if(k>n){
		if(check())ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;++i)
		if(!flag[i]){
			flag[i]=1;
			st[k]=i;
			dfs(k+1);
			flag[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)scanf("%1d",&s[i]),special&=s[i];
	for(int i=1;i<=n;++i)cin>>c[i];
	sort(c+1,c+n+1);
	cout<<upper_bound(c+1,c+n+1,upper_bound(c+1,c+n+1,0)-c-1)-c<<"\n";
	if(special==1){
		int usm=1;
		for(int i=1;i<=n;++i)sum*=i,sum%=mod;
		cout<<sum;
		return 0;
		int t=n;
		n=upper_bound(c+1,c+n+1,upper_bound(c+1,c+n+1,0)-c-1)-c-1;
		dfs(1);
		
		ll dp[MAXN][MAXN];
		
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*

100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19


*/
