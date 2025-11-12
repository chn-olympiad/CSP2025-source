#include <bits/stdc++.h>
using namespace std;
void qread(int &x)
{
    x = 0;
    char s = getchar();
    while (s != ' ' && s != '\n')
    {
        x *= 10;
        x += (s - '0');
        s = getchar();
    }
}
void QW(int x)
{
    if (x == 0)
    {
        return;
    }
    QW(x / 10);
    putchar((x % 10) + '0');
}
void qwhrite(int x)
{
    if (x == 0)
    {
        putchar('0');
        return;
    }
    QW(x);
}
int arr[500005];
int num[500005];
int n, k;
struct Duan
{
    int l;
    int r;
};
bool cmp(Duan a, Duan b)
{
    if (a.l != b.l)
    {
        return a.l < b.l;
    }
    return a.r < b.r;
}
Duan all[5005];
int allHave;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    // cin >> n >> k;
    qread(n);
    qread(k);
    int l, r;
    l = 0;
    r = 0;
    for (int i = 0; i < n; i++)
    {
        // cin >> arr[i];
        qread(arr[i]);
        if (i == 0)
        {
            num[i] = arr[i];
        }
        else
        {
            num[i] = arr[i] ^ num[i - 1];
        }
    }
    // for(int i=0;i<n;i++){
    //     cerr<<arr[i]<<" ";
    // }
    // cerr<<endl;
    // for(int i=0;i<n;i++){
    //     cerr<<num[i]<<" ";
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == 0)
            {
                if (num[j] == k)
                {
                    all[allHave].l = i;
                    all[allHave].r = j;
                    allHave++;
                }
            }
            else
            {
                int now = num[j] ^ num[i - 1];
                if (now == k)
                {
                    all[allHave].l = i;
                    all[allHave].r = j;
                    allHave++;
                }
            }
        }
    }
    sort(all, all + allHave, cmp);
    int ans = 0;
    int ln = 0;
    for (int i = 0; i <= allHave; i++)
    {
        ans++;
        ln = all[i].r;
        while (all[i].l <= ln)
        {
            i++;
        }
    }
    // cout << ans;
    qwhrite(ans);
    return 0;
}