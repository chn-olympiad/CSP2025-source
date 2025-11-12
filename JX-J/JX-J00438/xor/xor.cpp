#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[1000],b=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==0){b++;}
    }
    if(k==0){
    cout<<b;
    }
    if(n==1){
    cout<<1;
    return 0;
    }
    if(k>=1){cout<<n/2;}

    return 0;
}
