#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,F=1e3+10;
int n,k;
int a[N],b[N];
int dis[N];
int main()
{

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
   scanf("%d%d",&n,&k);
   int f=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]!=0||a[i]!=1) f=1;
    }
    if(f==1&&k==1&&n>=F)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1) ans++;
        }
        cout<<ans;
        return 0;
    }
    else if(f==1&&k==0&&n>=F)
    {
        int ans=0,u=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                ans++;
                ans+=u/2;
                u=0;
            }
            else if(a[i]==1)
            {
                u++;
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int s=0;
       for(int j=i;j>=1;j--)
       {
           s=s^a[j];
           if(s==k)
           {
               dis[i]=max(dis[i],dis[j-1]+1);
           }

       }
       dis[i]=max(dis[i],dis[i-1]);
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<dis[i];
    }*/
   cout<<dis[n];
    return 0;
}
