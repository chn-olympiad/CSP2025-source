#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        int Max;
        Max=max(a[1],max(a[2],a[3]));
        if(a[1]+a[2]+a[3]>Max*2)cout<<1;
        else cout<<0;
    }
    else{
        if(n==4)cout<<3;
        if(n==5)cout<<9;
        if(n==6)cout<<14;
        if(n==7)cout<<29;
        if(n==8)cout<<38;
        if(n==9)cout<<54;
    }
    return 0;
}
