#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    if(n==3){
        if(a[n]*2<sum){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<(n*(n-2))/3;
    }
    return 0;
}
