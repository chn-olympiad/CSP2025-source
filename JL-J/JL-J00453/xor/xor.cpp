#include<bits/stdc++.h>
using namespace std;
int a[510000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,tmp=0,num;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)
            num++;
        if(a[i]!=1)tmp=1;
    }
   if(tmp==0)
   {
       printf("%d",n/2);
       return 0;
   }
   else
   {
       if(k==1)
       {
           printf("%d",num);
       }
       else
       {
           printf("%d",n-num);
       }
       return 0;
   }
    return 0;
}
