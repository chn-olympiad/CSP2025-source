#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
struct node{
	int s;
	int e;
};
int cmp(node bjx,node bjd){
	return bjx.s<bjd.s;
}
node b[500005];
int c[500005];
int ans;
void hs(int s,int e,int cgs){
	if(s==e+1)ans=max(ans,cgs);
	else{
		for(int u=1;u<=e;u++){
			int f=0;
			for(int i=b[u].s;i<=b[u].e;i++)if(c[i]==1)f=1;
			if(f==0){
				for(int i=b[u].s;i<=b[u].e;i++)c[i]=1;
				ans=max(ans,cgs+1);
				hs(s+1,e,cgs+1);
				for(int i=b[u].s;i<=b[u].e;i++)c[i]=0;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int dp[n+2][n+2],g=0;
	for(int i=1;i<=n;i++)dp[i][i]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i!=j)dp[i][j]=a[j]^dp[i][j-1];
			if(dp[i][j]==k){
				g++;
				b[g].s=i;
				b[g].e=j;
				break;
			}
		}
	}
	hs(1,g,0);
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
