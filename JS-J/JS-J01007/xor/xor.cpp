#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[505000];
int ans;
bool fg;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        fg=1;
    }
    if(!fg)
    {
        ans=ans/2;
        cout<<ans;
        return 0;
    }
    else
    {
        if(k==0)
        {
           for(int i=1;i<=n;i++)
           {
               if(a[i]==k)
               {
                   ans++;
               }
               else
               {
                   if(a[i+1]==a[i])
                   {
                       ans++;
                       i++;
                   }
               }
           }
           cout<<ans;
           return 0;
    }else
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==k)
                    ans++;
            }
            cout<<ans;
            return 0;
        }
    }
    return 0;
}
