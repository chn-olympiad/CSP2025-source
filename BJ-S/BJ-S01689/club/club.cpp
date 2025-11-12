#include <bits/stdc++.h>
using namespace std;

int d[100005];
struct node
{
    int a,b,c,d,m;
}a[100005];
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
  int t,n;
  cin>>t;
  for(int i=1;i<=t;i++)
  {
      int idx1=0,idx2=0,idx3=0,idx4=0,ans=0;
      memset(d,0,sizeof(d));
      cin>>n;
      for(int j=1;j<=n;j++)
      {
          cin>>a[j].a>>a[j].b>>a[j].c;
          if(a[j].a>=a[j].b&&a[j].a>=a[j].c)
          {
              idx1++,a[j].d=1,a[j].m=a[j].a;
          }
          else if(a[j].b>=a[j].a&&a[j].b>=a[j].c)
          {
              idx2++,a[j].d=2,a[j].m=a[j].b;
          }
          else
          {
              idx3++,a[j].d=3,a[j].m=a[j].c;
          }
      }
      if(idx1>n/2)
      {
            for(int j=1;j<=n;j++)
            {
                if(a[j].d==1)
                {
                d[++idx4]=min(a[j].a-a[j].b,a[j].a-a[j].c);
                }
            }
            sort(d+1,d+idx4+1);
            for(int j=1;j<=idx1-n/2;j++)
            {
                ans-=d[j];
            }
       }
       else if(idx2>n/2)
       {
            for(int j=1;j<=n;j++)
            {
                if(a[j].d==2)
                {
                    d[++idx4]=min(a[j].b-a[j].a,a[j].b-a[j].c);
                }
            }
            sort(d+1,d+idx4+1);
            for(int j=1;j<=idx2-n/2;j++)
            {
                ans-=d[j];
            }
        }
        else if(idx3>n/2)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[j].d==3)
                {
                    d[++idx4]=min(a[j].c-a[j].a,a[j].c-a[j].b);
                }
            }
            sort(d+1,d+idx4+1);
            for(int j=1;j<=idx3-n/2;j++)
            {
                ans-=d[j];
            }
        }
        for(int j=1;j<=n;j++)
        {
            ans+=a[j].m;
        }
        cout<<ans<<endl;
  }
  return 0;
}
