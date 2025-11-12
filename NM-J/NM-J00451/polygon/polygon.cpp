#include<bits.stdc++.h>
using namespace std;
int a[10000],n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3) cout<<0;
    if(n==3&&a[1]+a[2]+a[3]>a[3]*2) cout<<1;
    return 0;
}
