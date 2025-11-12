//J00694 at here
#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,k,a[500050];
int l[500050],d[500050];

void case1()
{
    for(int i = 1;i <= n;i++) l[i] = -1;

    for(int i = 1;i <= n;i++)
    {
        int now = 0;
        for(int j = i;j >= 1;j--)
        {
            now = (now ^ a[j]);
            if(now == k)
            {
                l[i] = j;
                break;
            }
        }
    }

//for(int i = 1;i <= n;i++) cout << l[i] << " ";
//cout << endl;

    for(int i = 1;i <= n;i++)
    {
        if(l[i] == -1)
        {
            d[i] = d[i-1];
            continue;
        }
        d[i] = d[i-1];
        d[i] = max(d[i-1],d[l[i]-1]+1);
    }

    cout << d[n];
}

void case2()
{
    if(k == 1)
    {
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == 1) cnt++;
        }
        cout << cnt;
    }
    else
    {
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == 1)
            {
                if(a[i+1] == 1)
                {
                    cnt++;
                    i++;
                }
            }
            else cnt++;
        }
        cout << cnt;
    }
}

signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];

    if(n <= 2000)
    {
        case1();
        return 0;
    }

    int maxn = 0;
    for(int i = 1;i <= n;i++) maxn = max(maxn,a[i]);
    if(maxn <= 1)
    {
        case2();
        return 0;
    }

    for(int i = 1;i <= n;i++) l[i] = -1;

    int last = 0;

    for(int i = 1;i <= n;i++)
    {
        int now = 0;
        for(int j = i;j > last;j--)
        {
            now = (now ^ a[j]);
            if(now == k)
            {
                l[i] = j;
                last = j;
                break;
            }
        }
    }

    for(int i = 1;i <= n;i++)
    {
        if(l[i] == -1)
        {
            d[i] = d[i-1];
            continue;
        }
        d[i] = d[i-1];
        d[i] = max(d[i-1],d[l[i]-1]+1);
    }

    cout << d[n];
    return 0;
}
