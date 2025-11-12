#include<iostream>
#include<algorithm>
#define LL long long

using namespace std;

const int NR=2e4;
const int MR=1e6+10;

int n,m,k;

LL c[30];
LL kw[30][NR];

LL ts=0;
int cnt=0;
struct Edge{
    int u,v;
    LL w;
}a[MR],t[NR],tt[NR];

bool cmp(Edge x,Edge y){
    return x.w<y.w;
}

int st[NR];

int fs(int u){
    if(st[u]==u)return u;
    return st[u]=fs(st[u]);
}

LL ans=1e18;
bool flag[30];
void dfs(int step,LL cost,int edgeCount){
    if(step>k){
        int nx=k+n;
        LL sum=0;
        for(int i=1;i<=edgeCount;i++){
            tt[i]=t[i];
        }
        sort(tt+1,tt+1+edgeCount,cmp);
        for(int i=1;i<=nx;i++){
            st[i]=i;
        }
        //for(int i=1;i<=k;i++)cout << flag[i] << " ";
        //cout << endl;
        for(int i=1;i<=edgeCount;i++){
            int u=fs(tt[i].u),v=fs(tt[i].v),w=tt[i].w;
            if(u==v)continue;
            st[u]=v;
            //cout << u << " " << v << " " << w << endl;
            sum+=w;
        }
        ans=min(ans,sum+cost);
        return;
    }
    flag[step]=false;
    dfs(step+1,cost,edgeCount);
    flag[step]=true;
    for(int i=1;i<=n;i++){
        t[++edgeCount]={n+step,i,kw[step][i]};
    }
    dfs(step+1,cost+c[step],edgeCount);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        a[i]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        cin >> c[i];
        for(int j=1;j<=n;j++){
            cin >> kw[i][j];
        }
    }

    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=n;i++){
        st[i]=i;
    }
    for(int i=1;i<=m;i++){
        int u=fs(a[i].u),v=fs(a[i].v),w=a[i].w;
        if(u==v)continue;
        st[u]=v;
        t[++cnt]={u,v,w};
        ts+=w;
    }

    if(k==0){
        cout << ts << endl;
        return 0;
    }
    
    dfs(1,0,cnt);

    cout << ans << endl;
}