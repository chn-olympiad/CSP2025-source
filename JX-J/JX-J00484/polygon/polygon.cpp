#include<bits/stdc++.h>
using namespace std;
int a[50001],l[50001],c[50001],k=0,h=0,z=0;
int p(int b,int n)
{
    memset(l,0,sizeof(l));
    for (int i=1;i<=n;i++)
    {
        if(i==b)
        {
            if(h>=2*c[b])
            {
                k++;
                h-=c[b];
                i--;
                continue;
                cout<<k<<endl;
            }
        }
        if(l[i]==0)
        {
            c[i]=a[i];
            h+=a[i];
            l[i]=1;
        }
        if(i+1==n&&z!=n-1)
        {
            i=1;
            memset(l,z,sizeof(l));
            l[z]=1;
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,k=0;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=3;i<=n;i++)
    {
        p[i,n];
    }
    cout<<k;
    return 0;
}
