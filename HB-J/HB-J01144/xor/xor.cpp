#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a[100000];
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        int sum = 0;
        int sum2 = 0;
        for(int j = i;j <= n;j++)
        {
            if(sum + a[j] <= k)
            {
                sum = sum + a[j];
                sum2++;
            }
            else
            {
                break;
            }
        }
        cnt = max(cnt,sum2);
    }
    cout << cnt;
    return 0;
}
