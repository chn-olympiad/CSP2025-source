#include <bits/stdc++.h>
using namespace std;
const int N=500;
int t,n,a[N+5][5],cnt[5],f[N+5][N+5][N+5];
int dfs(int u){
	if(u>n) return 0;
	if(f[cnt[1]][cnt[2]][cnt[3]]<0x7f7f7f7f) return f[cnt[1]][cnt[2]][cnt[3]];
	int res=0;
	for(int i=1;i<4;i++)
		if(cnt[i]<n/2){
			cnt[i]++;
			res=max(res,dfs(u+1)+a[u][i]);
			cnt[i]--;
		}
	return f[cnt[1]][cnt[2]][cnt[3]]=res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(f,0x7f,sizeof(f));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		printf("%d\n",dfs(1));
	}
	return 0;
}
