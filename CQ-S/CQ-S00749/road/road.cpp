#include <bits/stdc++.h>
#define int long long
#define maxn 2000005
using namespace std;
struct edge{
	int u,v,w;
}e[maxn],e2[maxn];
int n,m,cnt,fx,fy,k,x,ans = 0x3f3f3f3f3f3f3f3f,all,fa[maxn],c[15],num[15][10005];
int find(int x){
	return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
int answer(int x){
	cnt = m;
	int ans = 0;
	for (int i = 1;i <= m;i++) e2[i] = e[i];
	for (int i = 1;i <= k;i++){
		if (!(x>>(i-1)&1)) continue;
		ans += c[i];
		for (int j = 1;j <= n;j++) e2[++cnt] = {n+i,j,num[i][j]};
	}
	sort(e2+1,e2+cnt+1,[](edge a,edge b){
		return (a.w < b.w);
	});
	for (int i = 1;i <= n+k;i++) fa[i] = i;
	for (int i = 1;i <= cnt;i++){
		fx = find(e2[i].u),fy = find(e2[i].v);
		if (fx != fy) fa[fx] = fy,ans += e2[i].w;
	}
	return ans;
}
bool checkB(){
	for (int i = 1;i <= k;i++){
		if (c[i] != 0) return 0;
		bool flag = 0;
		for (int j = 1;j <= n;j++) flag |= num[i][j] == 0;
		if (flag == 0) return 0;
	}
	return 1;
}
signed main(){
	//freopen("D:\\road\\road3.in","r",stdin);
	#ifndef LOCAL
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k,all = k,cnt = m;
	for (int i = 1;i <= m;i++) cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1;i <= k;i++){
		cin >> c[i];
		for (int j = 1;j <= n;j++) cin >> num[i][j];
	}
	if (checkB()) ans = answer((1<<k)-1);
	else for (int i = 0;i < (1<<k);i++) ans = min(ans,answer(i));
	cout << ans;
	return 0;
}
