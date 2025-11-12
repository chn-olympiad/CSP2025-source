#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
long long fa[N],cut,csd=0;
long long chr(long long jd)
{
    if(fa[jd]!=jd)
    {
        fa[jd]=chr(fa[jd]);
        return fa[jd];
    }
    return jd;
}
long long bing(long long a,long long b)
{
    fa[chr(a)]=fa[chr(b)];
    return 0;
}
bool ji(long long a,long long b) {return chr(a)==chr(b);}
long long n,m,i,j,k,c[10][N];
struct bian
{
    long long u,v,q;
}a[N*100];
bool f(bian a,bian b)
{
    return a.q<b.q;
}
long long scs(long long size)
{
    long long ans=0,i,j,k;
    sort(a,a+size,f);
    for(i=0;i<N;i++) fa[i]=i;
    cut=0;
    for(i=0;i<size;i++)
    {
        if(ji(a[i].u,a[i].v)==0)
        {
            ans+=a[i].q;
            bing(a[i].u,a[i].v);
                a[cut].u=a[i].u;
                a[cut].v=a[i].v;
                a[cut++].q=a[i].q;
        }
    }
    return ans;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(i=0;i<N;i++) fa[i]=i;
    cin>>n>>m>>k;
    for(i=0;i<m;i++) {cin>>a[i].u>>a[i].v>>a[i].q;
        a[i].u--;
        a[i].v--;
    }
    long long ans=scs(m);
    for(i=0;i<k;i++)
    {
        for(j=0;j<=n;j++)
        {
            cin>>c[i][j];
            if(c[i][0]!=0) csd=1;
        }
    }
    if(csd==0&&k!=0)
    {
        for(i=0;i<k;i++)
        {
            for(j=1;i<=n;j++)
            {
                a[cut].u=n+i;
                a[cut].v=j-1;
                a[cut++].q=c[i][j];
            }
        }
        ans=scs(cut);
    }
    cout<<ans;
    return 0; 
}
