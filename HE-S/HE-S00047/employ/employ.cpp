#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;

int a[505];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int n,m;
    scanf("%d %d",&n,&m);

    string s;
    cin >> s;
    for(int i =1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }

    long long ans = 1;
    for(int i = n;i >= 1;i--)
    {
        ans = ans * i % p;
    }

    cout << ans;

    return 0;
}
