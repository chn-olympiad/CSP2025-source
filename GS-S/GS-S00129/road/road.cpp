#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int MAXN = 1e6+1e5+5;
long long read()
{
    long long num = 0;
    char ch = getchar();
    while(ch<48||ch>57)ch = getchar();
    while(ch>=48&&ch<=57)
    {
        num = (num<<3)+(num<<1)+ch-48;
        ch = getchar();
    }
    return num;
}
long long n,m,k;
long long cnt;
struct node
{
    long long u,v,w;
    bool operator<(const node& rhs)const{
        return w<rhs.w;
    }
}edges[MAXN];
long long c[15];
int pa[10015];
int p(long long u)
{
    if(u==pa[u])return u;
    return pa[u] = p(pa[u]);
}
void bing(long long u,long long v)
{
    int pu = p(u),pv = p(v);
    pa[pu] = pv;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = read(),m = read(),k = read();
    for(long long i = 1,u,v,w;i<=m;i++)
    {
        u = read(),v = read(),w = read();
        edges[++cnt] = {u,v,w};
    }
    for(int i = 1;i<=k;i++)
    {
        c[i] = read();
        for(int j = 1;j<=n;j++)
        {
            long long w;
            w = read();
            edges[++cnt] = {n+i,j,w};
        }
    }
    sort(edges+1,edges+cnt+1);
    cnt = 0;
    for(int i = 1;i<=n+k;i++)
    {
        pa[i] = i;
    }
    long long ans = 0;
    for(int i = 1;i<=m;i++)
    {
        if(cnt==n+k-1)break;
        long long u = edges[i].u,v = edges[i].v,w = edges[i].w;
        if(p(u)==p(v))continue;
        cnt++;
        ans+=w;
        bing(u,v);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//6 8 0
//1 3 2
//1 4 4
//2 4 5
//2 6 7
//4 6 3
//5 6 4
//1 5 8
//3 4 3


