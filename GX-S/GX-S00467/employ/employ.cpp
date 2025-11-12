#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
long long r[501];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    int l = s.size();
    for (int i = 0 ; i < n; i++)
    {
        cin >> r[i];
    }
    sort(r, r + n, cmp);
    long long cnt = 1;
    long long sum = 0;
    for (long long i = 0; i < l; i++)
    {
        for (long long j = 0; j < n; j++)
            if (r[j] <= i)
                sum++;
        cnt *= sum;
        sum = 0;
    }
    cout << cnt % 998244353;
    return 0;
}
