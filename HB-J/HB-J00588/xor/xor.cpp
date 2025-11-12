#include<bits/stdc++.h>
using namespace std;

long long a[500010];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    long long n,k,ans = 0;

    cin>>n>>k;

    long long f = 0;

    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];

        f ^= a[i];

        if(f == k || a[i] == k)
        {
            ans++;
            f = 0;
        }
    }

    cout<<ans;

    return 0;
}
