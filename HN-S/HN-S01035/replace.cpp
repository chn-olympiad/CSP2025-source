#include<bits/stdc++.h>
using namespace std;
bool st;
#define pii pair<int,int>
const int N=5e5+5;
int id(char x,char y){ return (x-'a'+1)*27+y-'a'+1; }
// unordered_map<int,int> tr[N];
// bool vis[N][300];
int tr[N][800];
int fail[N],ncnt[N],dep[N];
int fa[N][24],du[N];
vector<int> to[N];
// vector<pair<int,int> >nto[N];
int n,q,cnt;
char s1[N],s2[N];
// int fd(int now,int p){ return lower_bound(nto[now].begin(),nto[now].end(),pii(p,0))-nto[now].begin(); }
void work()
{
    cin>>s1+1;
    cin>>s2+1;
    int now=0,len=strlen(s1+1);
    for(int i=1;i<=len;i++)
    {
        int p=id(s1[i],s2[i]);
        if(!tr[now][p]) tr[now][p]=++cnt,dep[cnt]=dep[now]+1;
        now=tr[now][p];
    }
    ncnt[now]++;
}
void bfs()
{
    queue<int> q;
    for(int i=id('a','a');i<=id('z','z');i++)
        if(tr[0][i]) q.push(tr[0][i]);
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        // cerr<<u<<' '<<fail[u]<<' '<<ncnt[u]<<'\n';
        if(u==fail[u]) exit(0);
        // exit(0);
        // int fx=fail[u];
        for(int i=id('a','a');i<=id('z','z');i++)
        {
            if(tr[u][i])
                fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
        }
    }
}
void solve()
{
    int ans=0;
    cin>>s1+1; cin>>s2+1;
    if(strlen(s1+1)!=strlen(s2+1))
        return cout<<0<<'\n',void();
    int len=strlen(s1+1);
    int now=0,L=0,R=len+1;
    for(int i=1;i<=len;i++)
        if(s1[i]!=s2[i]) R=i;
    for(int i=len;i>=1;i--)
        if(s1[i]!=s2[i]) L=i;
    int mlen=R-L+1;
    bool f=(R==len+1&&L==0);
    // cout<<L<<' '<<R<<'\n';
    for(int i=1;i<=len;i++)
    {
        int p=id(s1[i],s2[i]);
        now=tr[now][p];
        // while(now&&!vis[now][p])
        //     now=fail[now];
        // if(!now) now=0;
        // else now=nto[now][fd(now,p)].second;
        if(f) ans+=ncnt[now];
        else if(i>=R)
        {
            if(dep[now]<mlen+i-R) continue;
            int x=now;
            for(int j=21;j>=0;j--)
                if(dep[fa[x][j]]>=mlen+i-R)
                    x=fa[x][j];
            ans+=ncnt[now]-ncnt[fa[x][0]];
        }
    }
    cout<<ans<<'\n';
}
void dfs(int x)
{
    fa[x][0]=fail[x];
    for(int i=1;fa[x][i-1];i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int v:to[x]) ncnt[v]+=ncnt[x],dfs(v);
}
bool ed;
int main()
{
    // freopen("replace1.in","r",stdin);
    // freopen("replace.out","w",stdout);
    // printf("%.5lf",(&ed-&st)/1024.0/1024);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    // cerr<<n<<' '<<q<<'\n';
    for(int i=1;i<=n;i++) work();
    // for(int i=1;i<=cnt;i++) sort(nto[i].begin(),nto[i].end());
    // cerr<<'?';
    // exit(0);
    bfs();
    // cerr<<'?';
    for(int i=1;i<=cnt;i++) to[fail[i]].push_back(i);
    dfs(0);
    while(q--) solve();
}