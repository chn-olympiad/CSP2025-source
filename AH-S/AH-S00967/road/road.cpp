#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k, u, v, cnt, h[10005];
long long w,ans;
long long a[15][10005], c[15], fa[10005], r[1000005];
struct node{
	int v, w, p;
}e[2000005];
//vector <node> s[10005];
void add(int u, int v, int w){
	e[++cnt].p=h[u]; e[cnt].v=v; h[u]=cnt;e[cnt].w=w;
}
void initbcj(){
	for (int i=1; i<=n; i++) fa[i]=i;
}
/*int Find(){
	return x==fa[x]? x: x=fa[x];
}*/
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    initbcj();
    for (int i=1; i<=m; i++){
        scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
        r[cnt>>1]=w;
    }
    for (int i=1; i<=k; i++){
        scanf("%lld", &c[i]);
        for (int j=1; j<=n; j++){
            scanf("%lld", &a[i][j]);
        }
    }
    sort(r+1,r+(cnt>>1)+1);
    for (int i=1; i<n; i++)
        ans+=r[i];
    printf("%lld", ans);
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4 
100 1 3 2 4
*/
