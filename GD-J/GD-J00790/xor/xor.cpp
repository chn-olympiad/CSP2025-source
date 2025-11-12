#include <bits/stdc++.h>
using namespace std;
int n, ans;
long long k, a[500005];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int ind = 0;
    long long x = 0;
    while(ind < n)
    {
        x = x ^ a[ind];
        if(x == k)
        {
            ans++;
            ind++;
            x = 0;
        }
        else
        {
            ind++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
