# include<bits/stdc++.h>
# define int long long
# define endl "\n"
using namespace std;
const int maxn=2e4+5, maxm=1.5e6+5, INF=0x7fffffff;
struct Node{
    int u, v, w, next;
} edge[maxm*2];
int n, m, k, cnt=0, head[maxn], vis[maxn], c[15][maxn], a[maxn], mmin=-1;
int fa[maxn];
bool flag1=true, flag2=true;
void add(int u, int v, int w) {
    edge[++cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
bool cmp(Node a, Node b) {
    return a.w<b.w;
}
void read(int &x) {
    x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0' && c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
}
int f(int u) {
    if(fa[u]==u) return u;
    return fa[u]=f(fa[u]);
}
signed main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++) {
        int u, v, w;
        read(u); read(v); read(w);
        add(u, v, w);
    }
    for(int u=1; u<=k; u++) {
        read(c[u][0]);
        if(c[u][0]) flag1=false;
        bool tmp=false;
        for(int v=1; v<=n; v++) {
            read(c[u][v]);
            if(c[u][v]==0) tmp=true, a[u]=v;
        }
        if(tmp==false) flag2=false;
    }
    if(flag1==false || flag2==false) {
        for(int u=1; u<=k; u++) {
            for(int v=1; v<=n; v++) {
                add(u+n, v, c[u][v]);
            }
        }
        sort(edge+1, edge+cnt+1, cmp);
        for(int x=0; x<(1<<k); x++) {
            for(int i=1; i<=n+k; i++) fa[i]=i;
            int lst=n+k-1, ans=0;
            for(int i=1; i<=k; i++) {
                if((1<<(i-1))&x) {
                    ans+=c[i][0];
                }
            }
            for(int i=1; i<=cnt; i++) {
                if(lst==0) break;
                int u=edge[i].u, v=edge[i].v, w=edge[i].w;
                if(f(u)==f(v)) continue ;
                if((v<=n || ((1<<(v-n-1))&x)) && (u<=n || ((1<<(u-n-1))&x))) {
                    ans+=w, fa[f(u)]=f(v);
                    lst--;
                }
            }
            if(mmin==-1) mmin=ans;
            mmin=min(ans, mmin);
        }
        cout << mmin << endl;
    } else {
        for(int i=1; i<=k; i++) {
            for(int j=1; j<=n; j++) {
                add(a[i], j, c[i][j]);
            }
        }
        sort(edge+1, edge+cnt+1, cmp);
        for(int i=1; i<=n; i++) fa[i]=i;
        int lst=n-1, ans=0;
        for(int i=1; i<=cnt; i++) {
            if(lst==0) break;
            int u=edge[i].u, v=edge[i].v, w=edge[i].w;
            if(f(u)==f(v)) continue ;
            ans+=w, fa[f(u)]=f(v); lst--;
        }
        cout << ans << endl;
    }
    fclose(stdin); fclose(stdout);
	return 0;
}
