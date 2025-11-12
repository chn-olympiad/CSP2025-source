#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int a[100005];

bool check(int n){
    for(int i=0;i<n;i++)
        if(a[i]!=1)return false;
    return true;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n==3){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        if(a>c)swap(a,c);
        if(b>c)swap(b,c);
        if(a+b>c)cout<<1;
        else cout<<0;
    }
    else{
        for(int i=0;i<n;i++)cin>>a[i];
        long long ch=2;
        if(check(n)){
            long long ans=1;
            for(int i=0;i<n;i++){
                ans*=ch;
                ans%=MOD;
            }
            ans+=MOD;
            ans+=MOD;
            ans+=MOD;
            ans+=MOD;
            long long asd=1;
            ans-=asd;
            long long nco=n;
            ans-=nco;
            ans-=nco*(nco-asd)/ch;
            ans%=MOD;
            cout<<ans;
        }
    }
    return 0;
}
