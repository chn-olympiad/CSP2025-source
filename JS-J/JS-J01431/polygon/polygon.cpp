#include<bits/stdc++.h>
using namespace std;
bool cmp(long long s,long long y)
{

    return s > y;
}
long long n,a[10005],dp[10005],ans;
void v(long long i,long long mx,long long sum,long long num)
{

    if(i > n)
    {
        if((sum > (mx * 2)) && (num >= 0))
        {
            ans ++;
            //cout << num << ' ' << sum << ' ' << mx << endl;
            ans %= 998244353;
        }
        return ;
    }
    v(i + 1,max(mx,a[i]),sum + a[i],num + 1);
    v(i + 1,mx,sum,num);
}
int main()
{
    freopen("polygon1.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    /*sort(a + 1,a + 1 + n,cmp);
    for(int i = 1;i <= n;i ++)
    {

        dp[i] = a[i] + dp[i - 1];
    }*/
    /*for(int i = 1;i <= n;i ++)
    {
        for(int j = i + 2;j <= n;j ++)
        {
            if(dp[j] - dp[i - 1] <= (a[j] * 2))
            {
                continue;
            }
            else
            {

                ans ++;
                ans %= 998244353;
            }
        }
    }*/
    v(1,0,0,0);
    cout << ans;
    return 0;
}
