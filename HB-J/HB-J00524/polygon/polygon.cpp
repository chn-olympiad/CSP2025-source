#include<bits/stdc++.h>
using namespace std;
const int N = 5000;
int n;
int a[N];
int p[N];
int sum;
int ans;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] + a[i];
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n - i + 1; j++)
        {
            int l = j + 1, r = i + j;
            sum = p[r] - p[l - 1];
            if(sum >= r + 1){
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
