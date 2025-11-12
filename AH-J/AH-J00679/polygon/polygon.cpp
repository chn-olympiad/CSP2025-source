#include <bits/stdc++.h>
using namespace std;
long long n,sum=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int a,b,c,d;
    if(n<=3)
    {

        cin>>a>>b>>c;
        if(a+b>c&&a+c>b&&a+b>c)
        {
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else
    {
        if(n==4)
        {
            cin>>a>>b>>c>>d;
            if(a+b!=c+d||a+c!=b+d||a+d!=b+c)
            {
                cout<<2;
            }
            else
            {
                cout<<0;
            }
        }
    }
    return 0;
}
