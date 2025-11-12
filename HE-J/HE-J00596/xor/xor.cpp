# include<bits/stdc++.h>
using namespace std;
long long n,m,r,summ,l,k;
int a[500000];
long long dp[500005];
void dfs(long long x,long long y,long long z,bool p){
	if(y>n){
		dp[n]=max(dp[n],z);
	    return;
	}
	if(z<dp[y]) return;
	dp[y-1]=z;
	if(!y) dfs(x,y+1,z,1);
	else{
		if(!p) x+=a[y];
		else x=abs(x-a[y]);
		if(x==k) dfs(0,y+1,z+1,0);
		else dfs(x,y+1,z,p);
	}
	if(!x) dfs(0,y+1,z,0);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,1,0,0);
	cout<<dp[n];
	return 0;
}
