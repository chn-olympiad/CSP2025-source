#include<bits/stdc++.h>
using namespace std;
int n,a[3199],m=3,max1,ans=0;
bool pd(int j,int k){
    int sum=0;
    for(int i=j;i<=k;i++)
    {
        sum+=a[i];
        //max1=max(max1,a[i]);
    }
    for(int i=j;i<=k;i++)
    {
        if(a[i]>=sum)
        {
            return false;
        }
    }
    return true;
}
int main()
{
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>a[i];
   }
   m=n;
    while(m>=3)
    {
            for(int i=1;i<=m-2;i++)
            {
                if(pd(i,m))
                {
                    ans++;
                    for(int i=1;i<=m;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
                }
            }

        m--;
    }
    cout<<ans;
    return 0;
}
