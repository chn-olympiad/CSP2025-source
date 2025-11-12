#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,a[5001];
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        if(a[i]>a[i+1])
        {
            cout << a[i]+a[i+1];
            return 0;
        }
    }
    return 0;
}

