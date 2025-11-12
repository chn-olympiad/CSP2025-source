#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a[n + 1] = {0};
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == m)
        {
            cnt++;
            a[i] = -1;
        }
    }
    for(int i =0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int x = 0;
            for(int k = i; k <= j; k++)
            {
                x ^= a[k];
            }
            if(x == m)
            {
                cnt++;
                for(int k= i; k < j; k++) a[k] = -1;
            }
            //cout << i << " " << j << " " << cnt <<endl;
        }
    }
    cout << cnt;
}
