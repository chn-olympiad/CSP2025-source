#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3)
    {
		 printf("0");
		 return 0;
    }
    int sum=0,mx=0;
    for(int i=1;i<=n;i++)
    {
           scanf("%d",&a[i]);
           sum+=a[i];
           mx=max(mx,a[i]);
     }
    if(n==3)
    {
        if(a[1]+a[2]>a[3]||a[1]+a[3]>a[2]||a[2]+a[3]>a[1]) printf("1");
        else printf("0");
    }
    return 0;
}
