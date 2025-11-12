#include<bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++)
        cin >> a[i];
    int k = a[1];
    sort(a + 1,a + n * m + 1);
    reverse(a + 1,a + n * m + 1);
    for(int i = 1;i <= n * m;i++)
        if(a[i] == k)
        {
            k = i;
            break;
        }
    cout << (k - 1) / n + 1 << " " << (((k - 1) % (2 * n)) < n ? k % (2 * n) : n - ((k - 1) % n)) << endl;
    return 0;
}
