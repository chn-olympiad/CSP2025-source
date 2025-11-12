#include<bits/stdc++.h>
using namespace std;
int n,a[10000000];
int main(){
    freopen("ploygon.in","r",stdin);
    freopen("ploygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]+a[2]+a[3]>max(a[1],max(a[2,a[3])){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
