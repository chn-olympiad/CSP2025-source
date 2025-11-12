#include<bits/stdc++.h>
using namespace std;
int a[100010][4],x[100010],y[100010],z[100010],f[100010];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=3; j++)
            {
                cin>>a[i][j];
            }
        }
        int xnum=0,ynum=0,znum=0,ans=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
            {
                x[++xnum]=a[i][1]-max(a[i][2],a[i][3]);
                ans+=a[i][1];
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
            {
                y[++ynum]=a[i][2]-max(a[i][1],a[i][3]);
                ans+=a[i][2];
            }
            else
            {
                z[++znum]=a[i][3]-max(a[i][2],a[i][1]);
                ans+=a[i][3];
            }
        }
        int num;
        if(xnum>n/2)
        {
            num=xnum;
            for(int i=1; i<=num; i++)
            {
                f[i]=x[i];
            }
        }
        else if(ynum>n/2)
        {
            num=ynum;
            for(int i=1; i<=num; i++)
            {
                f[i]=y[i];
            }
        }
        else if(znum>n/2)
        {
            num=znum;
            for(int i=1; i<=num; i++)
            {
                f[i]=z[i];
            }
        }
        else
        {
            cout<<ans<<endl;
            continue;
        }
        sort(f+1,f+num+1);
        for(int i=1; ; i++)
        {
            ans-=f[i];
            num--;
            if(num<=n/2)
            {
                break;
            }
        }
        cout<<ans<<endl;
    }
}
