#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,h0=0,h1=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n%2==0)
    {
        cout << n << endl;
    }
    else if(n%2==1)
    {
        cout << n-1 << endl;
    }
    return 0;
}
