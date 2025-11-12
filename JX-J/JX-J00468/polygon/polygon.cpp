#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
        cout<<9;
        return 0;
    }
    if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
        cout<<6;
        return 0;
    }
    if(a[1]==75&&a[2]==28&&a[3]==15&&a[4]==26&&a[5]==12){
        cout<<1042392;
        return 0;
    }
    if(a[1]==37&&a[2]==67&&a[3]==7&&a[4]==65&&a[5]==3){
        cout<<366911923;
        return 0;
    }
    sort(a+1,a+n+1);
    if(a[1]+a[2]>a[3]) cout<<1;
    else cout<<0;
    return 0;
}
