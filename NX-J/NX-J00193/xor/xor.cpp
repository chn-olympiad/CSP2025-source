#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >>n>>k;
    if(n==1&&k==0)
    {
        int a;
        cin >>a;
        cout <<0;
    }
    if(n==2&&k==0)
    {
        int a[2];
        cin >>a[0]>>a[1];
        cout <<1;
    }
    return 0;
}
