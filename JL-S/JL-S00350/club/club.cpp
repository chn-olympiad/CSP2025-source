#include<bits/stdc++.h>
using namespace std;
int t,n,a[10],b[10],c[10],d[10],e[10],f[10],g[10],h[10];
int main(){
    freopen("club.in","r",stdin);
    freopen("clud.out","w",stdout);
    cin>>t;
    {
        for(int x=1;x<=t;x++)
        {
            cin>>n;
            if(n==2)
            {
                for(int i=1;i<=3;i++)
                cin>>a[i];
                for(int i=1;i<=3;i++)
                cin>>b[i];
                for(int i=1;i<=3;i++)
                {
                    c[i]=i;
                    d[i]=i;
                }
                for(int i=1;i<=3;i++)
                {
                    for(int j=i;j<=3-i;j++)
                    {
                        if(a[j]<a[j+1])
                        {
                            swap(a[j],a[j+1]);
                            swap(c[j],c[j+1]);
                        }
                    }
                }
                for(int i=1;i<=3;i++)
                {
                    for(int j=1;j<=3-i;j++)
                    {
                        if(b[j]<b[j+1])
                        {
                            swap(b[j],b[j+1]);
                            swap(d[j],d[j+1]);
                        }
                    }
                }
                if(c[1]!=d[1])
                cout<<a[1]+b[1];
                if(c[1]==d[1])
                cout<<max(a[2]+b[1],a[1]+b[2]);
            }
            if(n==4)
            {
                for(int i=1;i<=3;i++)
                cin>>a[i];
                for(int i=1;i<=3;i++)
                cin>>b[i];
                for(int i=1;i<=3;i++)
                cin>>e[i];
                for(int i=1;i<=3;i++)
                cin>>f[i];
                for(int i=1;i<=3;i++)
                {
                    c[i]=i;
                    d[i]=i;
                    g[i]=i;
                    h[i]=i;
                }
                for(int i=1;i<=3;i++)
                {
                    for(int j=i;j<=3-i;j++)
                    {
                        if(a[j]<a[j+1])
                        {
                            swap(a[j],a[j+1]);
                            swap(c[j],c[j+1]);
                        }
                    }
                }
                for(int i=1;i<=3;i++)
                {
                    for(int j=1;j<=3-i;j++)
                    {
                        if(b[j]<b[j+1])
                        {
                            swap(b[j],b[j+1]);
                            swap(d[j],d[j+1]);
                        }
                    }
                }
                for(int i=1;i<=3;i++)
                {
                    for(int j=1;j<=3-i;j++)
                    {
                        if(e[j]<e[j+1])
                        {
                            swap(e[j],e[j+1]);
                            swap(g[j],g[j+1]);
                        }
                    }
                }
                for(int i=1;i<=3;i++)
                {
                    for(int j=1;j<=3-i;j++)
                    {
                        if(f[j]<f[j+1])
                        {
                            swap(f[j],f[j+1]);
                            swap(h[j],h[j+1]);
                        }
                    }
                }
                if(c[1]!=d[1]&&d[1]!=g[1]&&c[1]!=g[1]||c[1]!=d[1]&&d[1]!=h[1]&&c[1]!=h[1]||c[1]!=g[1]&&g[1]!=h[1]&&c[1]!=h[1]||d[1]!=g[1]&&g[1]!=h[1]&&d[1]!=h[1])
                cout<<a[1]+b[1]+e[1]+f[1];
            }
        }
    }

    return 0;
}
