#include"bits/stdc++.h"
using namespace std;
const int N = 5 * 100000;
int a[N + 10],n,k,b[N + 10],cnt = 0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    b[1] = a[1];
    for(int i = 2;i <= n;i++)
    {
        b[i] = a[i] ^ b[i - 1];
        if(b[i] == k)
            cnt += 1;
    }
    for(int i = 1;i <= n;i++)
        cout << b[i] << " ";
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == k)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
