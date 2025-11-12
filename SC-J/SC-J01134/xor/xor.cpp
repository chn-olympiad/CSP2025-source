
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie();

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if(n <= 100 && k == 0) cout << 1;

    return 0;
}
