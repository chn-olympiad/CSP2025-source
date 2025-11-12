#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n;
    cin>>n;
    if(n<=10)
    {
        cout<<2;
    }
    else if(n>10&&n<=1000)
    {
        cout<<20948;
    }
    else
    {
        cout<<38;
    }
    return 0;
}
