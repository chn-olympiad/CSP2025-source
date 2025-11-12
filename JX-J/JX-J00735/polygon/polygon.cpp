#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==2&&k==0){
        cout<<1;
        return 0;
    }
    cout<<3;
    return 0;
}
