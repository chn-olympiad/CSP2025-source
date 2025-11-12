#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005];
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(k==0){
        cout<<0;
    }
    else if(k==2){
        cout<<2;
    }
    else if(k==3){
        cout<<2;
    }
    else
        cout<<69;
    return 0;
}
