#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,ans=0,a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    if((a+b+c)>2*a && (a+b+c)>2*b && (a+b+c)>2*c) ans++;
    cout<<ans;


    return 0;
}


