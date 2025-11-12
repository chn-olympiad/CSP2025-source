#include<bits/stdc++.h>
using namespace std;
long long t=0,a[10000001],b[10000001],c[10000001],n;
long long vis[1001];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int maxx=-1e6;
        memset(vis,0,sizeof(vis));
        //int tt=3*n/2;
        cin>>n;
        //tt=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        int n1=n;
        //for(int i=1;i<=n;i++)
        //{
        //cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
        //}
       int i=1,j=1,k=1;
       int xx=0,kk=0,zz=0;
       for(int i=1;i<=n;i++)
       {
           xx+=b[i];
           kk+=b[i];
           zz+=c[i];
       }
       /*if(zz==0)
       {
           for(i=1,j=1;;i++,j++)
           {
               if(j==n&&i==n&&n1<n/2)
               {
                   break;
               }
               if(a[i]>maxx)
               {
                   maxx=a[i];
               }
               if(b[j]>maxx)
               {
                   maxx=b[j];
               }
               if(a[i]==maxx&&vis[1]<=n/2)
               {
                   i++;
                   vis[1]++;
                   ans+=a[i];
                   n1--;
               }
               if(b[j]==maxx&&vis[2]<=n/2)
               {
                   j++;
                   vis[2]++;
                   ans+=b[j];
                   n1--;
               }
           }
           cout<<ans<<endl;
           continue;
       }
       */
       if(xx==0&&zz==0)
       {
           for(int i=1;i<=n/2;i++)
           {
               ans+=b[i];
           }
           cout<<ans<<endl;
           continue;
       }
       if(kk==0&&zz==0)
       {
           for(int i=1;i<=n/2;i++)
           {
               ans+=a[i];
           }
           cout<<ans<<endl;
           continue;
       }
        while((i!=n&&j!=n&&k!=n)&&n1>=n/2)
        {
            if(n1<n/2)
            {
                break;
            }
            int maxx=-1e6;
           if(a[i]>maxx)
           {
               maxx=a[i];
           }
           if(b[j]>maxx)
           {
               maxx=b[j];
           }
           if(c[k]>maxx)
           {
               maxx=c[k];
           }
           //cout<<maxx<<endl;
            if(a[i]==maxx&&vis[1]<=n/2)
            {
                ans+=a[i];
                i++;
                vis[1]++;
                n1--;
            }
            if(b[j]==maxx&&vis[2]<=n/2)
            {
                ans+=b[j];
                j++;
                vis[2]++;
                n1--;
            }
            if(c[k]==maxx&&vis[3]<=n/2)
            {
                ans+=c[k];
                k++;
                vis[3]++;
                n1--;
            }
        }
        cout<<ans<<endl;//<<" "<<i<<" "<<j<<" "<<k<<" "<<vis[2]<<" "<<n1<<endl;
    }
    return 0;
}
