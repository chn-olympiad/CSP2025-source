#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 10005,M = 1000005;
struct roads {int x,y,d;} tt[M],p[N],orip[N];
inline bool cmp(roads x,roads y) {return x.d < y.d;}
int fa[N];
inline int findroot(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = findroot(fa[x]);
}
int n,m,k,xa[11][N],a[11][N],cntori;
long long ans;
inline long long eval(int s)
{
    long long now = 0; int cntp = cntori;
    memcpy(p,orip,sizeof(p));
    for(int i = 1;i <= k;i++)
        if(s&(1<<(i-1)))
        {
            now += a[i][0];
            for(int j = 1;j <= n;j++)
                p[++cntp] = (roads){n+i,j,a[i][j]};
        }
    sort(p+1,p+1+cntp,cmp); // cout << cntp << endl;
    for(int i = 1;i <= n+k;i++) fa[i] = i;
    for(int i = 1;i <= cntp;i++)
        if(findroot(p[i].x) != findroot(p[i].y))
        {
            fa[findroot(p[i].x)] = findroot(p[i].y);
            now += p[i].d;
        }
    return now;
}
inline void dfs(int x,int s,long long cur)
{
    ans = min(ans,cur);
    for(int i = x;i <= k;i++)
    {
        s += (1<<(i-1));
        long long tmp = eval(s);
        if(tmp < cur) dfs(i+1,s,tmp);
        s -= (1<<(i-1));
    }
}
int rs[11],rsdd[11];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i++) scanf("%d%d%d",&tt[i].x,&tt[i].y,&tt[i].d);
    for(int i = 1;i <= k;i++)
        for(int j = 0;j <= n;j++)
            scanf("%d",&xa[i][j]);
    // random shuffle
    srand(time(0));
    for(int i = 1;i <= k;i++)
    {
        rs[i] = rand() % k + 1;
        while(rsdd[rs[i]]) rs[i] = rand() % k + 1;
        rsdd[rs[i]] = 1;
    }
    for(int i = 1;i <= k;i++)
        for(int j = 0;j <= n;j++)
             a[i][j] = xa[rs[i]][j];
    // compute
    sort(tt+1,tt+1+m,cmp);
    cntori = 0;
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 1;i <= m;i++)
        if(findroot(tt[i].x) != findroot(tt[i].y))
        {
            p[++cntori] = tt[i];
            fa[findroot(tt[i].x)] = findroot(tt[i].y);
            ans += tt[i].d;
        }
    memcpy(orip,p,sizeof(p));
    dfs(0,0,ans);
    printf("%lld\n",ans);
    return 0;
}
