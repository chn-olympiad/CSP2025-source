#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,flag = 1,deno = 998244353;
    cin >> n;
    int stick[n+1];
    for(int i = 1;i <= n;i++)
    {
        cin >> stick[i];
        if(stick[i] != 1)
        {
            flag = 0;
        }
    }
    if(flag == 1)
    {
        long long ans = 0;
        for(int i = 3;i <= n;i++)
        {
            long long tmp1 = 1,tmp2 = 1;
            for(int j = n;j >= n-i+1;j--)
            {
                tmp1 *= j;
            }
            for(int j = 2;j <= i;j++)
            {
                tmp2 *= j;
            }
            ans += (tmp1/tmp2) % deno;
            ans %= deno;
        }
        cout << ans << endl;
        return 0;
    }
    sort(stick+1,stick+n+1);
    long long cnt = 0;
    for(int i = 3;i <= n;i++)
    {
        int sum = 0;
        int element = i - 1;
        int operate = pow(2,element);
        int chg[element + 1];
        memset(chg,0,sizeof(chg));
        for(int j = 1;j < operate;j++)
        {
            int pos = element;
            while(chg[pos] == 1)
            {
                chg[pos] = 0;
                sum -= stick[pos];
                pos--;
            }
            chg[pos] = 1;
            sum += stick[pos];
            if(sum > stick[i])
            {
                cnt++;
            }
        }
    }
    cout << cnt % deno << endl;
    return 0;
}
