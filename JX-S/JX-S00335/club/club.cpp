#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100][100];
bool ff(int x,int y)
{
    for(int i=1;i<=x;i++)
    {
        for(int j=2;j<=y;j++)
        {
            if(a[i][j]!=0)
            {
                return 1;
            }
       }
    }
    return 0;
}
int main()
{
  //freopen("club.in","r",stdin);
  //freopen("club.out","w",stdout);
    cin>>t;
    int g[1000000];
    while(t--)
    {
        memset(g,0,sizeof(g));
        memset(a,0,sizeof(a));
        int b=0,c=0,d=0,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }
        }
        if(ff(n,3)==0)
        {
            for(int i=1;i<=n;i++)
            {
                 g[i]=a[i][1];
            }
            sort(g+1,g+n+1);
            for(int i=n;i>n/2-1;i++)
            {
                sum+=g[i];
            }
            cout<<sum<<endl;
        }
      for(int i=1;i<=n;i++)
      {
          int p=INT_MIN,y=0;
          for(int j=1;j<=3;j++)
          {
              if(a[i][j]>p)
              {
                 p=a[i][j];
                  y=j;
              }
          }
          if(y==1&&b<n/2) b++;
          else if(y==2&&c<n/2) c++;
          else if(y==3&&d<n/2) d++;
          sum+=p;
      }
      cout<<sum<<endl;
    }
    return 0;
}
