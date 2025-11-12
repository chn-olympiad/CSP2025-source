#include <bits/stdc++.h>

using namespace std;

long long k;
int n;
long long a[500010];
int cnt = 500005, ans;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        if(a[i] != k)
        {
            int x = a[i];
            cnt = i + 1;
            while(x != k && a[cnt] != k && cnt <= n)
            {
                x ^= a[cnt];
                cnt++;
            }
            if(x == k || a[cnt] == k)
                ans++, i = cnt;
        }
        else
            ans++;
    }
    cout << ans;
}