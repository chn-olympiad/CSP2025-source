#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
int a[N][5];
int ans,r1,r2,r3;
int g1,g2,g3;
int main()
         {
          freopen("club.in","r",stdin);
          freopen("club.out","w",stdout);
          cin>>t;
          for(int q=1;q<=t;q++)
          {
           cin>>n;
           int m=n/2;
           for(int i=1;i<=n;i++)
             for(int j=1;j<=3;j++)
            {
              cin>>a[i][j];
            }
           for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
           {
               g1=a[i][1];
               g2=a[i][2];
               g3=a[i][3];
               if(g1>g2&&g1>g3){
                if(r1<=m)
                  {++r1;
                  ans+=g1;}
                else if(g2>g3&&r2<=m)
                {++r2;
                ans+=g2;}
                else
                {++r3;
                ans+=g3;}
               }
               else if(g2>g1&&g2>g3)
               {
                   if(r2<=m)
                   {++r2;
                   ans+=g2;}
                   else if(g1>g3&&r1<=m)
                    {++r1;
                    ans+=g1;}
                   else
                    ++r3;
                    ans+=g3;
               }
               else if(g3>g2&&g3>g1)
               {
                   if(r3<m)
                   {
                     ++r3;
                     ans+=g3;
                   }
                   else if(g2>g1&&g2<=m)
                    {++r2;
                    ans+=g2;}
                   else
                    {++r1;
                    ans+=g1;}
               }
               else
               {
                if(g1==g2)
                {
                   if(g3<g2)
                   {
                       if(r1<=m)
                       {++r1;
                       ans+=g1;}
                       else if(r2<=m)
                       {
                           ++r2;
                           ans+=g2;
                       }
                       else
                       {
                           ++r3;
                           ans+=g3;
                       }
                   }
                   else
                    {
                       if(r1<=m)
                       {
                           ++r1;
                           ans+=g1;
                       }
                       else if(r2<=m)
                       {
                           ++r2;
                           ans+=g2;
                       }
                       else
                       {
                           ++r3;
                           ans+=g3;
                       }
                    }
              }
              else if(g2=g3)
               {
                   if(g1<g2)
                   {
                       if(r2<=m)
                       {++r2;
                       ans+=g2;}
                       else if(r3<=m)
                       {
                           ++r3;
                           ans+=g3;
                       }
                       else
                       {
                           ++r1;
                           ans+=g1;
                       }
                   }
                   else
                    {
                       if(r1<=m)
                       {
                           ++r1;
                           ans+=g1;
                       }
                       else if(r2<=m)
                       {
                           ++r2;
                           ans+=g2;
                       }
                       else
                       {
                           ++r3;
                           ans+=g3;
                       }
                    }
               }
               else{
                    if(r1<=m)
                       {
                           ++r1;
                           ans+=g1;
                       }
                       else if(r2<=m)
                       {
                           ++r2;
                           ans+=g2;
                       }
                       else
                       {
                           ++r3;
                           ans+=g3;
                       }
                    }

               }
            g1=0;
            g2=0;
            g3=0;
          }
          cout<<ans<<endl;
          ans=0;
        }
        return 0;
    }
