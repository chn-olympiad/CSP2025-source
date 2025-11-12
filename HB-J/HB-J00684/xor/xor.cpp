#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k;
    int sum = 0;
    cin >> n >> k;
    for(int i = 1; i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n ; i++)
    {
        if(a[i] == k)
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
