#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500100
#define MN -9982443533
ll T,n,a[N][4],ans,bz[N],d[N],nd,jl[N];
template<typename T>inline void read(T &x)
{
    bool f=1;x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=!f;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=(f?x:-x);return;
}
template<typename T>inline void write(T x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    read(T);
    while(T--)
    {
        ans=nd=0;
        d[1]=d[2]=d[3]=0;
        read(n);
        for(int i=1;i<=n;i++) bz[i]=0;
        for(int i=1;i<=n;i++)
        {
            ll tmp=0,id=0;
            for(int j=1;j<=3;j++)
            {
                read(a[i][j]);
                if(tmp<=a[i][j]) tmp=a[i][j],id=j;
            }
            jl[i]=id;
            d[id]++;
            ans+=tmp;
            sort(a[i]+1,a[i]+4,greater<ll>());
            bz[i]=a[i][2]-a[i][1];
        }
        if(d[1]-n/2>0)
        {
            nd=d[1]-n/2;
            for(int i=1;i<=n;i++) bz[i]=(jl[i]==1?bz[i]:MN);
        }
        if(d[2]-n/2>0)
        {
            nd=d[2]-n/2;
            for(int i=1;i<=n;i++) bz[i]=(jl[i]==2?bz[i]:MN);
        }
        if(d[3]-n/2>0)
        {
            nd=d[3]-n/2;
            for(int i=1;i<=n;i++) bz[i]=(jl[i]==3?bz[i]:MN);
        }
        sort(bz+1,bz+1+n,greater<ll>());
        for(int i=1;i<=nd;i++) ans+=bz[i];
        write(ans);
        putchar('\n');
    }
    return 0;
}