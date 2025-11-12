#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,maxv=(1<<20)+10;
int n,k;
int s[N],dp[N];
int g[maxv];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		s[i]=s[i-1]^x;	
	}
	
	for(int i=1;i<=(1<<20);i++) g[i]=-1;
	
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],g[s[i]^k]+1);
		g[s[i]]=max(g[s[i]],dp[i]);
	}
	
	cout<<dp[n]<<'\n';
	return 0;
}

