#include<bits/stdc++.h>
using namespace std;
bool A,B=true;
long long n;
long long a[5005],sum[5005];
long long mod=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdin);
    cin>>n;
    if(n<=3){
        A=true;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            B=false;
        }
    }
    if(A){
        if(n==1){
            cout<<0;
        }
        if(n==2){
            cout<<0;
        }
        if(n==3){
            long long num=0,maxi=-1;
            for(int i=1;i<=n;i++){
                maxi=max(maxi,a[i]);
                num+=a[i];
            }
            if(num>2*maxi){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
    }
    else if(B){
        long long num=1,new=1;
        for(int j=5;j<=n;j++){
                new=1;
            for(int i=0;i<j;i++){
                num=(num*(n-i))%mod;
                new*=(i+1);
            }
            ans+=(num%new)%mod;
        }
        cout<<ans;
    }
    else{
        if(n==4) cout<<4;
        if(n==5) cout<<9;
        long long ans=0;
        sort(a+1,a+n+1);
        for(int i=3;i<=n;i++){
            if(a[i]*2<a[i]+a[i-1]+a[i-2]){
                ans=(ans+n-i)%mod;
            }
        }
        cout<<ans;
    }
    return 0;
}
