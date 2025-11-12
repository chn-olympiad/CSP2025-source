#include <bits/stdc++.h>
using namespace std;

const int MOD=998244353;

long long C(int n,int m){
    double ans=1;
    for(int i=1,j=n;i<=m;i++,j--){
        ans=(ans*(j*1.0)/i);
    }
    return (long long)ans%MOD;
}

int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);


    int n;
    cin>>n;
    int a[n+5];
    bool checkin=false;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]!=1){
            checkin=true;
        }
    }
    if(n==1||n==2){
        cout<<0;
        return 0;
    }else if(n==3){
        sort(a+1,a+4);
        if(a[1]+a[2]>a[3]){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    if(checkin==false){
        long long sum=0;
        for(int i=3;i<=n;i++){
            sum=(sum+C(n,i))%MOD;
        }
        cout<<sum%MOD;
        return 0;
    }
    return 0;
}
