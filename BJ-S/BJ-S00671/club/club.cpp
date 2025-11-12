#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int n,ans,sum,T,f[N][4],g[4];
struct e { int w,id,id2; };
vector<e> t[4];
bool cmp1(e a,e b) { return a.w>b.w; }
struct node { 
    e b[10]={}; 
    void init() { sort(b+1,b+4,cmp1); }
} a[N];
bool cmp2(vector<e> a,vector<e> b) { return a.size()>b.size(); }
bool cmp3(e x,e y) { return a[x.id2].b[1].w-a[x.id2].b[2].w>a[y.id2].b[1].w-a[y.id2].b[2].w; }
void dfs(int d) {
    for(int i=1;i<=3;i++) {
        if(g[i]>n/2) return ;
    }
    if(d>n) {
        ans=max(ans,sum);
        return ;   
    }
    sum+=f[d][1];
    g[1]++;
    dfs(d+1);
    sum-=f[d][1];
    g[1]--;

    sum+=f[d][2];
    g[2]++;
    dfs(d+1);
    sum-=f[d][2];
    g[2]--;

    sum+=f[d][3];
    g[3]++;
    dfs(d+1);
    sum-=f[d][3];
    g[3]--; 
}
signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--) {
        sum=0,ans=0; memset(g,0,sizeof(g));
        for(int i=0;i<=3;i++)
            t[i].clear();
        cin>>n;
        if(n<=30) {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=3;j++)
                    cin>>f[i][j];
            dfs(1);
            cout<<ans<<'\n';
        }
        else {
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=3;j++) {
                    cin>>a[i].b[j].w;
                    a[i].b[j].id=j,a[i].b[j].id2=i;
                }
                a[i].init();
            }
            for(int i=1;i<=n;i++) {
                t[a[i].b[1].id].push_back(a[i].b[1]);
            }
            int p=0,s=0;
            for(int i=1;i<=3;i++)
                if(t[i].size()>s)
                    p=i;
            if(t[p].size()>n/2) {
                sort(t[p].begin(),t[p].end(),cmp3);
                int tt=t[p].size();
                for(int i=tt-1;i>=n/2;i--)
                    t[a[t[p][i].id2].b[2].id].push_back(a[t[p][i].id2].b[2]);
                for(int i=tt-1;i>=n/2;i--)  
                    t[p].pop_back();
            }
            for(int i=1;i<=3;i++)
                for(int j=0;j<t[i].size();j++)
                    ans+=t[i][j].w;
            cout<<ans<<'\n';
        }
    }
    return 0;
}