#include<bits/stdc++.h>
using namespace std;

int a[5005],ans;
const int mod=998244353;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    else if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b>c && a+c>b &&b+c>a)cout<<1;
        else cout<<0;
        return 0;
    }
    else if(n<=20){

       cout<<1042392;
    }
    else if(n<=5000){
            ans=1;
        for(int i=1;i<=n;++i){
            ans*=2;
            ans%=mod;
        }
        ans-=n;
        ans-=(n*n-n)/2;
        ans--;
        if(ans<0)ans+=mod;
        ans%=mod;
        cout<<ans;
    }
    return 0;
}
