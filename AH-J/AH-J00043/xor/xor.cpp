#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],xo[500005],cnt,nw,dp[500005];
struct Node{
	int be,en;
}no[1000005];
bool cmp(const Node &p1,const Node &p2){
	if(p1.en!=p2.en)	return p1.en<p2.en;
	return p1.be<p2.be;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf ("%d%d",&n,&k);
	for (int i=0;i<n;i++){
		scanf ("%d",&a[i]);xo[i+1]=a[i]^xo[i];
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if((xo[j]^xo[i-1])==k){
				no[cnt].be=i;no[cnt++].en=j;
			}
	sort(no,no+cnt,cmp);
	for(int i=1;i<=n;i++)
		if(nw==cnt||i!=no[nw].en)	dp[i]=dp[i-1];
		else{
			while(nw<cnt-1&&no[nw+1].en==no[nw].en)	nw++;
			dp[i]=max(dp[i-1],dp[no[nw].be-1]+1);nw++;
		}
	printf ("%d",dp[n]);
	return 0;
}
