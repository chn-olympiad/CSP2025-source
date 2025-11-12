#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,max;
    cin >> n;
    for(int i = 0;i<=n;i++)
    {
        max = n;
        if(n%2==0)
        {
            cout << max;
            break;
        }
    }
    return 0;
}
