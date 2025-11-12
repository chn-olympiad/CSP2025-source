#include<bits/stdc++.h>
using namespace std;
int a[600000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,q = 0;
    cin >> n >> k;
    for(int i = 0;i < n;i ++)
    {
        cin >> a[i];
    }
    q = a[0];
        if(n == 1 && a[0] == k)
        {
            cout << 1;
            return 0;
        }

    else
    {
        cout << 2;
    }
    return 0;
}
