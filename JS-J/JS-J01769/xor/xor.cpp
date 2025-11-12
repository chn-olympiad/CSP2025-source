#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int sum = 0,ans = 0;
    for(int i = 1;i <= n;i++)
    {
        sum^=a[i];
        if(sum==k)
        {
            sum = 0;
            ans++;
        }
    }
    int sum2 = 0,ans2 = 0;
    for(int i = n;i >= 1;i--)
    {
        sum2^=a[i];
        if(sum2==k)
        {
            sum2 = 0;
            ans2++;
        }
    }
    cout << max(ans,ans2);
    return 0;
}
