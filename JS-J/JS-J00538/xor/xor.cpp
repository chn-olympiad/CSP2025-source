#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   int n,k,b=-1;
   int s=0;
   cin>>n>>k;
   int a[n];
   for(int i=1;i<=n;i++)
    cin>>a[i];
    int start;
    for(int i=1;i<=n;i++)
    {
        start=i;
        if(a[start]==k)
           {
               s++;
           }
        else
        {
            int ans=0;
            for(int j= i;j<=n;j++)
            {
               ans^=a[j];
               if(ans==k)
               {
                   s++;
               start=j+1;
               if(start>n)
                break;
               }
               else continue;
            }

      }
       b=max(b,s);
    }
    cout<<b<<endl;
    return 0;
}
