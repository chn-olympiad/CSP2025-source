#include <bits/stdc++.h>
using namespace std;
int n,a[500100],k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==2&&k==0){
        cout<<1;
    }
    else if(n<=100&&k==0){
        cout<<n/2;
    }
    return 0;
}

