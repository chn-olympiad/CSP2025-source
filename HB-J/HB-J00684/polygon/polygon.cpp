#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n,sum = 0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    int ans = 0;
    for(int i = 1; i<= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    int maxn = -1;
    for(int i = 1; i<= n;i++)
    {
        if(a[i] > maxn)
        {
            maxn = a[i];
        }
    }
    if(ans > maxn*2)
    {
        sum++;
    }

    cout << sum;
    return 0;
}
