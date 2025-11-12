#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n;
    cin >> n;
    int ans = n;
    ans%=998244353;
    for(int i = 1;i<n;i++)
    {
        ans *= (n-i);
        ans%=998244353;
    }
    printf("%d",ans);
    return 0;
}
