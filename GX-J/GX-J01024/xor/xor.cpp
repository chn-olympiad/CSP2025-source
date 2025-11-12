#include <bits/stdc++.h>
using namespace std;
int t,tt,n,k,a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i <= n;i++)
        cin >> a[i];
    int l=1;
    for(int i=1;i <= n;i++)
    {
        int s=a[l];
        for(int j=l+1;j <= i;j++)
            s = a[j]^s;
        if(s==k)
        {
            l=i+1;
            t++;
        }
    }
    cout << t;
    return 0;
}
