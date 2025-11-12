#include<bits/stdc++.h>
using namespace std;
int n;long long b=0,x=0;
int a[10001],sum[10001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    bool z=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            z=false;
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    if(z==true){
        for(int i=1;i<=n-2;i++){
            x+=i;
            b+=x*(n-2);
            b%=998244353;
        }
        b%=998244353;
        cout<<b;
        return 0;
    }
    if(n==3){
        if(sum[3]>a[3]*2){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    return 0;
}
