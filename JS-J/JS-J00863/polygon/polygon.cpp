#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MOD = 998224353;
const int N = 5e3 + 10;

int r;
LL a[N];
LL sum[N];
LL res;
LL ans;
LL maxa;

void dfs(int m,int cnt,int now,LL summ,LL maxx)
{
    if(cnt == m)
    {
        if(summ > 2 * maxx)res++;
        return;
    }
    for(int i = now + 1;i <= r;i++)
    {
        dfs(m,cnt + 1,i,summ + a[i],max(maxx,a[i]));
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> r;
    for(int i = 1;i <= r;i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        maxa = max(maxa,a[i]);
    }
    if(r < 3)
    {
        cout << 0 <<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(maxa == 1)
    {
        LL last = 0,cnt = 1;
        for(int i = r;i >= 3;i--)
        {
            last += cnt;
            cnt++;
            ans = (ans + last) % MOD;
        }
        cout << ans <<endl;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }

    for(int m = 3;m <= r;m++)
    {
        res = 0;
        dfs(m,0,0,0,0);
        ans = ((ans % MOD) + (res % MOD)) % MOD;
    }
    cout << ans <<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
