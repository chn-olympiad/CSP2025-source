#include<bits/stdc++.h>
using namespace std;
int n,m,ans,c[505],d[505],vis[505];
char s[505];
void dfs(int k){
	if (k>n){
		int cnt=0;
		for (int i=1;i<=n;i++)
			if (cnt>=c[i]||s[d[i]]=='0') ++cnt;
		if (cnt>=m) ans++;
		return ;
	}
	for (int i=1;i<=n;i++)
		if (!vis[i]){
			vis[i]=1;
			d[k]=i;
			dfs (k+1);
			vis[i]=0;
		}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf ("%d%d\n%s",&n,&m,s+1);
	for (int i=1;i<=n;i++) scanf ("%d",&c[i]);
	dfs(1);printf ("%d",ans);
	return 0;
}

