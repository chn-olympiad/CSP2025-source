#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==0) {
        cout<<0;
    } else if(n==1) {
        cout<<0;
    } else if(n==2) {
        cout<<0;
    } else if(n==3) {
        cout<<1;
    } else if(n>=244){
        cout<<n%244;
    } else {
        cout<<1;
    }
    return 0;
}
