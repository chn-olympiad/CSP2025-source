#include <bits/stdc++.h>

using namespace std;

int a[100005];
vector<int> x;
vector<int> y;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int cnt = 0;
    int minN = 0, maxN = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {

            int sum = 0;
            for (int k = i; k < j; k++)
            {
                sum ^= a[k] ^ (a[k + 1]);
            }
            if (i == j)
                sum = a[i];
            if (sum == k)
            {
                bool flag = 1;
                if (flag)
                {
                    cnt++;
                    x.push_back(i);
                    y.push_back(j);
                }

            }
        }
    }
    cout << cnt;
}
