#include<bits/stdc++.h>
using namespace std;
int a[5][100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
        }
        sort(a[1]+1,a[1]+n+1,greater<int>());
        int ans=0;
        for(int i=1;i<=n/2;i++)
        {
            ans+=a[1][i];
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}