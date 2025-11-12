#include <bits/stdc++.h>
using namespace std;

int a[5005];
int s[5005];
int sum = 1;

int jc(int a)
{
    while(a > 0)
    {
        sum = sum * a;
        a--;
    }
    return sum;
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int jsq = 0;
    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j <= i - 1; i++)
        {
            for(int k = j; k <= i - 1; k++)
            {
                if(s[k] - s[k - j] >= a[i])
                {
                    jsq = (jsq + (jc(i - k + j) % 998244353) - (jc(i - j) % 998244353)) % 998244353;
                }
            }
        }
    }
    cout << jsq << endl;
    return 0;
}
