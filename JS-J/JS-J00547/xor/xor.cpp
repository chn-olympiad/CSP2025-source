#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005]={};
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            int sum=0;
            for (int k=i;k<=j;k++)
            {
                sum ^= a[k];
            }
            if (sum==k)
            {
                cnt++;
                i = j+1;
            }
        }
    }
    cout << cnt;
    return 0;
}
