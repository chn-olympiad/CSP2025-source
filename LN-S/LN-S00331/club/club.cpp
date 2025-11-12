#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
int a1[100001];
int a2[100001];
int a3[100001];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
        }
        sort(a1+1,a1+n+1);
        for(int i=n;i>n/2;i--)
        {
            ans+=a1[i];
        }
        printf("%d",ans);
        printf("\n");
        for(int i=1;i<=n;i++)
        {
            a1[i]=0;
            a2[i]=0;
            a3[i]=0;
        }
    }
    return 0;
}