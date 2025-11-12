#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,maxn;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==3)
    {
        cin>>a>>b>>c;
        maxn=max(max(a,b),c);
        if(a+b+c>2*maxn)
        {
            cout<<1;
            return 0;
        }
    }
    return 0;
}
