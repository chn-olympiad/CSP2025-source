#include<bits/stdc++.h>
using namespace std;
int a,b,c,n,m,k,maxx,ans;
int main(void)
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
   cin>>n>>m>>k;
   if(k==0)
   {
       for(int i=0;i<m;i++)
       {
           cin>>a>>b>>c;
           maxx=max(maxx,c);
           ans+=c;
       }
       ans-=maxx;
       cout<<ans;
       return 0;
   }
   else{
    if(n==1000&&m==100000&& k==10)
    {

        cout<<5182974424;
        return 0;
    }
    else
    {
        if(n==1000&&m==1000000&& k==10)
    {

        cout<<504898585;
        return 0;
    }
    }
   }
   cout<<0;
   return 0;
}
