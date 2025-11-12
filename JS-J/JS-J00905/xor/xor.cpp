#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    if(n%2==0) cout<<n/2;
    else cout<<n/2+1;
    return 0;
}
