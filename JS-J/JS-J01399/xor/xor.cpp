#include <bits/stdc++.h>
using namespace std;
int a[500005],d[500005];
struct node
{
    int l,r;
};
node p[500005];
int n,k,cnt = 0,ans = -1e7;

void dfs(int step,int lmt,int tot)
{
    if (step > cnt)
    {
        ans = max(ans,tot);
        return;
    }
    if(lmt < p[step].l)
    {
        dfs(step + 1,p[step].r,tot + 1);
    }

   if (p[step + 1].l < p[step].r)  dfs(step + 1,lmt,tot);
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        d[i] = int(a[i] ^ d[i - 1]);
    }
    for (int i = 1;i <= n;i++)
    {
        for (int j = i;j <= n;j++)
        {
            if (int(d[j] ^ d[i - 1]) == k)
            {
                cnt++;
                p[cnt].l = i;
                p[cnt].r = j;
                break;
            }
        }
    }
    dfs(1,0,0);
    cout << ans << endl;
    return 0;
}
