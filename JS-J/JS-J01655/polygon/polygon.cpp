#include<bits/stdc++.h>
using namespace std;
int a[5010];
const int mod = 998244353;
int max(int a,int b)
{
    return a<b?b:a;
}
int n;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    int maxx = 0;
    int sum =0;
    if(n == 3)
    {
        for(int i = 1;i<= n;i++)
        {
             {
            scanf("%d",&a[i]);
           maxx = max(a[i],maxx);
           sum+= a[i];

    }
        }
        if(sum > 2*maxx) printf("1\n");
        else printf("0\n");
        return 0;
    }

    for(int i = 1;i<= n;i++)
    {
        scanf("%d",&a[i]);
        maxx = max(a[i],maxx);
    }

    if(maxx == 1)
    {
        int ans = 1;
        for(int i = 1;i<= n;i++) (ans*=2)%mod;
        ans = (ans-n-(n-1)*n/2-1)%mod;
        printf("%d\n",ans);
        return 0;
    }
    return 0;
}
