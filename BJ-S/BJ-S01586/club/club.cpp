#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T, n, a[MAXN][5];
int maxn[MAXN];
int cnt[5];
bool book[MAXN][5];
int ans;
void dfs(int now, int sum)
{
    if(now>n)
    {
        ans=max(ans, sum);
        return;
    }
    for(int i=1; i<=3; i++)
    {
        if(cnt[i]+1 > (n/2)) continue;
        cnt[i]++;
        dfs(now+1, sum+a[now][i]);
        cnt[i]--;
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        ans=0;
        cnt[1]=0, cnt[2]=0, cnt[3]=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            //sum[1]+=a[i][1], sum[2]+=a[i][2], sum[3]+=a[i][3];
        }

        dfs(1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
