#include<iostream>
#include<vector>
#include<pair>
using namespace std;
const int MAXN = 5 * 1e5 + 5;
int n, k;
int a[MAXN], b[MAXN];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] ^ a[i];
    }
    cout << n << endl;
    return 0;
}
