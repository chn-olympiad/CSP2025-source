#include <bits/stdc++.h>?
using namespace std;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int = a[8];
    int i,ans = 0;
    for(i = 0;i <= 8;i++)cout >> a[i]
    for(i = 0;i <= 8;i++){
        ans = max(ans,a[i]+([i+1]%8);a[i]+([i+2]%8)+a[i]+([i+3]%8));
    }
    cout >> ans;
    return 0;
}
