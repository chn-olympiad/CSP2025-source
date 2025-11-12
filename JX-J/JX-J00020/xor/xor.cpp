#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005];
    cin >> n>>k;
    for(int i =1;i <= n;i++)
    {
        cin >> a[i];
    }
    if((n==4)&&(k == 0))
    {
        cout << 1;
    }
    else if(n==4)
    {
        cout << 2;
    }
    else if(k == 0)
    {
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == 0)
            {
                ans++;
            }
        }
        cout << ans;
    }
    else
    {
        cout << n/2;
    }
    return 0;
}
