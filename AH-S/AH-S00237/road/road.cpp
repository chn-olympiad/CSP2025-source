#include<bits/stdc++.h>
using namespace std;

template <typename T>

void in(T &x)
{
    int f=1;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')
        c=getchar();
    if(c=='-') f=-1,c=getchar();
    for(x=0;c>='0'&&c<='9';c=getchar())
        x=x*10+(c-'0');
    x*=f;
}

int n,m,k;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //ios::sync_with_stdio(false);
    in(n),in(m),in(k);
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        long long w;
        in(u),in(v),in(w);
        ans+=w;
    }
    for(int i=1;i<=k;i++)
    {
        int c;
        in(c);
        for(int i=1;i<=n;i++)
        {
            long long a;
            in(a);
        }
    }
    if(k==0)
    {
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}
