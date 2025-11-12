#include <bits/stdc++.h>
using namespace std;
#define int long long
#define len 1200000
struct edg{int f, x, y, s;} t[len], t2[len];
int ts2;
int n, m, k, fa[len], sum, ts, tans, ans=0x3f3f3f3f3f3f3f3f, v[11], cst[11];
bool cmp(const edg &a, const edg &b) {return a.s<b.s;}
int get(int x) {return fa[x]==x?x:get(fa[x]);}
void dfs(int x, int s, int c) {
	if(x==k+1) {
		sum=n+s, tans=c;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=ts2;i++) {
			if(!v[t2[i].f]) continue;
			if(get(t2[i].x)!=get(t2[i].y)) {
				fa[get(t2[i].x)]=get(t2[i].y), sum--;
				tans+=t2[i].s;
				if(sum==1) {
					ans=min(ans,tans);
					return;
				}
			}
		}
		return;
	}
	v[x]=0, dfs(x+1, s, c), v[x]=1, dfs(x+1, s+1, c+cst[x]);
	return;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k, ts=m;
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&t[i].x,&t[i].y,&t[i].s), t[i].f=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    sum=n;
    sort(t+1,t+m+1,cmp);
    for(int i=1;i<=ts;i++) {
        if(get(t[i].x)!=get(t[i].y)) {
            fa[get(t[i].x)]=get(t[i].y), sum--;
            t2[++ts2]=t[i];
            if(sum==1) break;
        }
    }
    for(int i=1;i<=k;i++) {
		cin>>cst[i];
		for(int j=1;j<=n;j++)
			ts2++, t2[ts2].x=n+i, t2[ts2].y=j, cin>>t2[ts2].s, t2[ts2].f=i;
	}
	sort(t2+1,t2+ts2+1,cmp);
	v[0]=1, dfs(1, 0, 0), cout<<ans;
	return 0;
}
