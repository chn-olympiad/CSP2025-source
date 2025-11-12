#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int qzh[10000005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int sum = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        qzh[i] = a[i] ^ qzh[i-1];
    }
    for(int i = 0;i <= n;i++)
    {
        for(int k1 =i+1;k1 <= n;k1++)
        {
            if((qzh[k1] ^ qzh[i]) == k)
            {
                i = k1;
                sum++;
            }
        }

    }
    cout << sum;
    return 0;
}
