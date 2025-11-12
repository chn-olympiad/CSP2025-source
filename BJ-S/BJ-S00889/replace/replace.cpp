#include<bits/stdc++.h>

using namespace std;
int n, q;
const int N = 510;
const int M = 5e6 + 10;
const int P = 131;
struct Node
{
    string a, b;
}p[N];
struct Mode
{
    int bg, ed;
}num[M];
bool cmp(Node a, Node b)
{
    return a.a.length() < b.b.length();
}

struct NU
{
    unsigned long long a, b;
}chuli[N];
unsigned long long a1[M], a2[M];
unsigned long long func(string a)
{
    int l = a.length();
    unsigned long long ans = 0;
    for(int i = 0; i < l; i ++ )
    {
        ans = ans * P + a[i] - 'a';
    }
    return ans;
}
unsigned long long qpow(unsigned long long a, long long b)
{
    unsigned long long ans = 1;
    while(b)
    {
        if(b & 1) ans = ans * a;
        else a = a * a;
    }
    return ans;
}
int main()
{
    freopen("repalce.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> p[i].a >> p[i].b;

    }
    sort(p + 1, p + n + 1, cmp);
    int pos = 0;
    num[pos].bg = 0;
    for(int i = 1; i <= n; i ++ )
    {
        if(pos != p[i].a.length())
        {
            num[pos].ed = i - 1;
            num[p[i].a.length()].bg = i;
            pos = p[i].a.length();
        }
    }
    num[pos].ed = n;
    for(int i = 1; i <= n; i ++ )
    {
        chuli[i].a = func(p[i].a), chuli[i].b = func(p[i].b);
    }
    for(int i = 1; i <= q; i ++ )
    {
        string c, d;
        cin >> c >> d;
        if(c.length() != d.length())
        {
            puts("0");
            continue;
        }
        int l1 = c.length(), l2 = d.length();
        for(int j = 0; j < l1; j ++ )
        {
            a1[j] = a1[j - 1] * P + c[j] - '0';
        }
        for(int j = 0; j < l2; j ++ )
        {
            a2[j] = a2[j - 1] *P + d[j] - '0';
        }
        int ans = 0;
        for(int len = 1; len <= l1; len ++ )
        {
            for(int l = 0; l + len - 1 < l1; l ++ )
            {
                int r = l + len - 1;
                cout << r << " ";
                for(int i = num[pos].bg; i <= num[pos].ed; i ++ )
                {
                    if(a1[l - 1] == a2[l - 1] && (unsigned long long)(a1[l1] - qpow(P, l1 - r) * a1[r]) == (unsigned long long)(a2[l1] - qpow(P, l2 - r) *a2[l1]))
                    {
                        ans ++ ;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
