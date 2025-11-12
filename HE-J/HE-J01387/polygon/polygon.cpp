#include <bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
bool vis[5005];
long long ans=0;
void dfs(int k,int l) {
	if(k==l) {
		int sum=0,maxn=0;
		for(int i=1;i<=k;i++) {
			sum+=b[i];
			maxn=max(maxn,b[i]);
		}
		if(sum>2*maxn) {
			ans++;
		}
		return;
	}
	
	for(int i=1;i<=n;i++) {
		if(vis[i]) {
			continue;
		}
		vis[i]=true;
		b[k]=a[i];
		dfs(k+1,l);
		vis[i]=false;
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int len=3;len<=n;len++) {
		dfs(1,len);
	}
	int p=ans%998;
	p=p%244;
	p=p%353;
	printf("%d",p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
