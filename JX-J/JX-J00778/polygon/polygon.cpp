#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[50005];
long long c(int x){
    if(x==1)return 1;
    else return x*c(x-1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=3){
        if(n<3) {cout<<0; return 0;}
        sort(a+1,a+1+n);
        if(a[1]+a[2]+a[3]>a[3]+a[3]){
            cout<<1;
            return 0;
        }
    }
    else{
        for(int i=3;i<=n;i++){
            ans+=c(n)/c(n-i)/2;
        }
    }
    cout<<ans;
}

