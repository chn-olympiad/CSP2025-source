#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[5001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<=2;i++){
        cin>>a[i];
        m=max(a[i],a[i+1]);
    }
    if(a[0]+a[1]+a[2]>=m*2){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
}
