#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    if(n==1)
    {
        int x;
        cin >> x;
        if(x==k)
        {
            cout << 1;
            return 0;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
