#include <bits/stdc++.h>
using namespace std;
const int N=505;
const long long mod=998244353;
int n,m;
int a[N],c[N];
int b[N],v[N];
int ans=0;
/*
3 2
101
1 1 2
*/
void dfs(int u) {
	if (u==n+1) {
		int cntci=0,cnt=0;
		for (int i=1;i<=n;i++) {
			if (cntci>=c[b[i]]||a[i]==0) {
				cntci++;
				continue;
			}
			cnt++;
		}
		if (cnt>=m) ans++;
		return;
	}
	for (int i=1;i<=n;i++) {
		if (v[i]) continue;
		v[i]=1;
		b[u]=i;
		dfs(u+1);
		b[u]=0;
		v[i]=0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++) {
		char ch;
		cin>>ch;
		a[i]=ch-'0';
	}
	for (int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
	}
	dfs(1);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

