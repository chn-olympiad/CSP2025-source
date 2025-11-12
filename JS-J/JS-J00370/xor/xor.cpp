#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xop.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005];
    cin >> n >> k;
    for(int i = 1;i<=n;i++)
        cin >> a[i];
    int ans = 0,sum;
    for(int i = 1;i<=n;i++)
    {
        sum = a[i];
        if(a[i] != k)
        {
            for(int j = i+1;j <= n;j++)
            {
                sum ^= a[j];
                if(sum == k)
                {
                    i = j+1;
                    break;
                }
            }
        }
        ans++;
    }
    cout << ans;
}
