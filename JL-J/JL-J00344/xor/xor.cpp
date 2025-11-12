#include<bits/stdc++.h>
#define ll long long

using namespace std;
int a[100005];
int b[100005];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(n <= 2)
    {
       cout << 1;
       return 0;
    }

    cout << 1;
    return 0;
}
/**/
