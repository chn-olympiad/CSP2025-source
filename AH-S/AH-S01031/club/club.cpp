#include<bits/stdc++.h>
using namespace std;
int zd(int a1,int a2,int a3)
{
    if(a1>=a2)
    {
        if(a1>=a3)
        return a1;
        else
        return a3;
    }
    if(a2>a1)
    {
        if(a2>=a3)
        return a2;
        else
        return a3;
    }
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int d[100010];
    int n;
    int ans=0;
    int x[100010],y[100010],z[100010],a[100010];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=a[i];j++)
        {
            cin>>x[j]>>y[j]>>z[j];
           }
         for(int k=1;k<=a[i];k++)
         {
             d[k]=zd(x[k],y[k],z[k]);
         }
         for(int k=1;i<=a[i];k++)
         {
             ans+=d[k];
         }
         cout<<ans<<endl;
         ans=0;
     }
     fclose(stdin);
     fclose(stdout);
     return 0;
 }



