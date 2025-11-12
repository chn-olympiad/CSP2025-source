#include <bits/stdc++.h>
using namespace std;
int n, m, g;
int a[150], b[150];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int k = n*m;
    for(int i = 0;i < k;i++) cin >> a[i];
    int r = a[0];
    sort(a, a+k);
    for(int i = k-1;i >= 0;i--) b[k-i-1] = a[i];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(b[i * n + j] == r)
            {
                cout << i+1 <<" "<<j+1<<endl;
                break;
            }
        }
    }
    return 0;
}