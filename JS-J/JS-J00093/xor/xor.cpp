#include<bits/stdc++.h>

using namespace std;

struct node{
    int a, b;
};

bool cmp(node a, node b)
{
    return a.b < b.b;
}

node m[500005];
int a[500005] = {0};
int s[500005] = {0};
int n, k, sum = 0, ans = 1;
int ma = 10000000, mi = 10000000;

int xx(int l, int r)
{
    if(l == 0) return s[r];
    return s[r] ^ s[l - 1];
}

int maxx(int a, int b)
{
    if(a > b) return a;
    return b;
}

int minn(int a, int b)
{
    if(a < b) return a;
    return b;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    s[0] = a[0];

    for(int i = 1; i < n; i ++)
    {
        s[i] = s[i - 1] ^ a[i];
    }

    for(int lenn = 0; lenn < n; lenn ++)
    {
        for(int l = 0; l < n; l ++)
        {
            int r = l + lenn;
            if(xx(l, r) == k)
            {
                //cout << xx(l, r) << " " << l << " " << r << "   |   ";
                /*if((l >= mi && l <= ma)||(r >= mi && r <= ma) || (mi >= l && mi <= r)||(ma >= l && ma <= r))
                {
                    //cout << "1\n";
                    continue;
                }
                mi = minn(l, mi);
                ma = maxx(ma, r);
                */
                //cout << mi << " " << ma << "  ";
                //cout << l << " " << r << endl;
                m[sum].a = l;
                m[sum].b = r;
                sum ++;

            }
        }
    }
    sort(m, m + sum, cmp);
    ma = m[0].b;
    mi = m[0].a;
    //cout << sum << endl;
    //cout << mi << " " << ma << endl;
    for(int i = 1; i < sum; i ++)
    {
        if(m[i].a > ma)
        {
            ans ++;
            ma = m[i].b;
            mi = m[i].a;
        }
    }
    //cout << endl;
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}

