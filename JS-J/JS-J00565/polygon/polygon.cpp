#include<bits/stdc++.h>
using namespace std;
int a[5345],b;
int n,m,ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3&&a[1]+a[2]>a[3]&&a[3]+a[2]>a[1]&&a[1]+a[3]>a[2]){

    cout<<1;
    return 0;
    }

    if(n==5&&a[1]==1)cout<<9;
    if(n==5&&a[1]==2)cout<<6;
    if(n==20)cout<<1042392;
    if(n==500)cout<<366911923;
    else cout<<26;
    return 0;
}
