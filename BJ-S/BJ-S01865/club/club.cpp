#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,ans = 0,a[100005][3];
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
        {
            scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
        }
        for(int i = 0;i < n;i++)
        {
            int cnt = a[0][i];
            for(int j = 0;j < n;j++)
            {
                if(i == j)
                    continue;
                cnt += a[1][j];
                ans = max(cnt,ans);
                cnt -= a[1][j];
            }
        }
        printf("%d\n",ans);
    }
}
