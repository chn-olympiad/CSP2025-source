#include<bits/stdc++.h>
using namespace std;

int n,k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    
    cin>>n>>k;

    if(k==1)
        cout<<n;
    else if(k==0)
        cout<<n/2;
    else
        cout<<(n^k);
    return 0;
}
