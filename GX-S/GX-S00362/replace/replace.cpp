#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<string>
#define int long long
using namespace std;
int n,m;
string a[10100],b[10010];
struct nx
{
   int lenl;
   int wz;
}c[10010],d[10010];
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
       cin>>a[i]>>b[i];
       c[i].lenl=a[i].size()-1;
       d[i].lenl=c[i].lenl;
    }
    if (n<=100)
    {
      for (int i=1;i<=m;i++)
      {
       int ans=0;
       string x,y;
       cin>>x>>y;
       int len=x.size()-1;
       for (int j=1;j<=n;j++)
       {
          int len1=a[j].size()-1;
          for (int k=0;k<=len-len1;k++)
          {
              string x2="",y2="",z2="";
              y2=x.substr(k,len1+1);
              if (y2!=a[j]) continue;
              if (k!=0)
                x2=x.substr(0,k);
              if (k+len1!=len)
                z2=x.substr(k+len1+1,len-(k+len1));
              if (x2+b[j]+z2==y)
                 ans++;
          } 
         }
       cout<<ans<<endl;
      }
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
           for (int j=0;j<=c[i].lenl;j++)
               if (a[i][j]=='b')
               {
                 c[i].wz=j;
                 break;
               }
           for (int j=0;j<=d[i].lenl;j++)
               if (b[i][j]=='b')
               {
                 d[i].wz=j;
                 break;
               }
        }    
        for (int i=1;i<=m;i++)
        {
            string x,y;
            cin>>x>>y;
            int ans=0;
            int flag=0,flag1=0;
            int lenx=x.size()-1;
            for (int j=0;j<=lenx;j++)
               if (x[j]=='b')
               {
                 flag=j;
                 break;
               }
           for (int j=0;j<=lenx;j++)
               if (y[j]=='b')
               {
                 flag1=j;
                 break;
               }
           for (int i=1;i<=n;i++)
           {
                 if (flag1-flag==d[i].wz-c[i].wz)
                   if (flag-c[i].wz>=0 && flag+(c[i].lenl-c[i].wz)<=lenx)
                     ans++;
           }
           cout<<ans<<endl;
        }        
    }
    return 0;
}

