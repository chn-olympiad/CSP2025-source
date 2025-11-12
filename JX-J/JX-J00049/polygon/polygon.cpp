#include <bits/stdc++.h>
using namespace std;
int main()
{//63
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>>m[i];
    if(n<3)cout<<0;
    else if(n==3)cout<<1;
    else if(n>3)cout<<n+n-1;
    return 0;
}
