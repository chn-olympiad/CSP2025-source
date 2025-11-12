#include<bits/stdc++.h>
using namespace std;
int n,a[5010],vis[5010],b[5010],sum,maxn,ans;
void dfs(int k){
	if(k>3&&k<=n+1){
		sum=0;
		maxn=0;
		for(int i=1;i<k;i++){
			sum+=b[i];
			maxn=max(maxn,b[i]);
		}
		if(sum>2*maxn){
			ans++;
			ans%=998244353;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&b[k-1]<=a[i]){
			b[k]=a[i];
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
			b[k]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(1);
	printf("%d",ans%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
