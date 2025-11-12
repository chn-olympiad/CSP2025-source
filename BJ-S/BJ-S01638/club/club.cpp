#include<bits/stdc++.h>
#define ll long long
#define MN 100010
using namespace std;

struct node{
    int sum,p;
};

int t;
int n;
int num[4][MN];
int cnt[4];
bool bo[MN];
node sum[MN];
ll ans;

bool compNode(node a,node b){return a.sum > b.sum;}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int maxn = 0;
        cnt[1] = 0,cnt[2] = 0,cnt[3] = 0;
        ans = 0;
        memset(bo,0,sizeof(bo));
        memset(sum,0,sizeof(sum));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d%d",&num[1][i],&num[2][i],&num[3][i]);
            maxn = max({num[1][i],num[2][i],num[3][i]});
            if(num[1][i] == maxn)  cnt[1]++;
            if(num[2][i] == maxn)  cnt[2]++;
            if(num[3][i] == maxn)  cnt[3]++;
        }
        int pmx,p1,p2;
        if(cnt[1] >= cnt[2])
        {
            if(cnt[1] >= cnt[3])
                pmx = 1,p1 = 2,p2 = 3;
            else
                pmx = 3,p1 = 1,p2 = 2;
        }
        else
        {
            if(cnt[2] >= cnt[3])
                pmx = 2,p1 = 1,p2 = 3;
            else
                pmx = 3,p1 = 1,p2 = 2;
        }
        if(cnt[pmx] <= (n >> 1))
        {
            for(int i = 1; i <= n; i++)
                ans += max({num[1][i],num[2][i],num[3][i]});
        }
        else
        {
            for(int i = 1; i <= n; i++)
            {
                if(num[p1][i] >= num[p2][i])
                    sum[i].sum = num[pmx][i] - num[p1][i],sum[i].p = i;
                else
                    sum[i].sum = num[pmx][i] - num[p2][i],sum[i].p = i;
            }
            sort(sum + 1,sum + n + 1,compNode);
            for(int i = 1; i <= (n >> 1); i++)
                bo[sum[i].p] = true;
            for(int i = 1; i <= n; i++)
            {
                if(bo[i])
                    ans += num[pmx][i];
                else
                    ans += max(num[p1][i],num[p2][i]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
