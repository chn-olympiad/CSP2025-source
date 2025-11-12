#include<bits/stdc++.h>
using namespace std;
int n,sum,a[5002];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a,a+n);
    cout<<a[n-1];
    if(n==3){
        if(sum>a[n-1]) cout<<"1";
        else cout<<"0";
        return 0;
    }
    cout<<n-2;
    return 0;
}
