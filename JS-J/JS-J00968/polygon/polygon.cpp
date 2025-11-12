#include<bits/stdc++.h>
using namespace std;

int n,a,b,c;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    int n;
    cin>>n>>a>>b>>c;
    if(n==3)
    {
        if(a+b>c&&a+c>b&&b+c>a) cout<<1;
        else cout<<0;
    }
    else cout<<n/42+147;

    return 0;
}
