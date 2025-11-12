#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5 * 1e5 + 10;
int a[N];
int n, k;
int ret = 0;
int cnt_ret = 0;

void dfs(int lst, int now)
{
    int llst = now;
    if(now >= n)
    {
        int tmp = a[lst];
        for(int i = lst + 1;i <= now;i++)
        {
            int tmpp = tmp;
            tmp = (tmpp ^ a[i]);
        }
        if(tmp == k)
        {
            cnt_ret++;
        }
        if(cnt_ret > ret)
        {
            ret = cnt_ret;
            cnt_ret = 0;
        }
        return;
    }
    int tmp = a[lst];
    for(int i = lst + 1;i <= now;i++)
    {
        int tmpp = tmp;
        tmp = (tmpp ^ a[i]);
    }
    if(tmp == k)
    {
        cnt_ret++;
    }

    for(int len = 0;len <= n - now;len++)
    {
        dfs(llst, now + len);
    }
}

signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }

    if(k <= 1)
    {
        int ret1 = 0;
        for(int i = 1;i <= n;i += 2)
        {
            if((a[i] ^ a[i] + 1) == 1)
            {
                ret1++;
            }
        }

        int ret2 = 0;
        if(a[1] == 1)
        {
            ret2++;
        }
        for(int i = 2;i <= n;i += 2)
        {
            if((a[i] ^ a[i + 1]) == 1)
            {
                ret2++;
            }
        }

        int ret3 = 0;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == 1)
            {
                ret3++;
            }
        }

        cout << max(max(ret1, ret2), ret3) <<endl;
    }
    else
    {
        dfs(1, 1);
        /*
        int ret = 0;
        for(int leftt = 1;leftt <= n;leftt++)
        {//zuo_duan_dian
            for(int len = 0;len <= n - leftt;len++)
            {
                cout << "left:" << leftt << " right:" << leftt + len << endl;
                int tmp = a[leftt];
                for(int k = leftt + 1;k <= leftt +len;k++)
                {
                    int tmpp = tmp;
                    tmp = (tmpp ^ a[k]);
                }
                if(tmp == k)
                {
                    cout << "tmp:" << tmp << endl;
                    ret++;
                }
            }
        }
    */
        cout << ret << endl;
    }
    return 0;
}
