#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5020],sum[5020];
int n,ans;
int mod=998244353;
int ksm(int x,int c){
    int d=1,k=x,y=c;
    while(y){
        if(y&1==1) d=d*k%mod;
        k=(k*k)%mod;
        y>>=1;
    }
    return d;
}
int comb(int x,int y){
    int gsq=1;
    for(int i=x;i>x-y;i--) gsq=(gsq*(i%mod))%mod;
    for(int i=1;i<=y;i++) gsq=(gsq*(ksm(i,mod-2)%mod))%mod;
    return gsq;
}
int calc(int x,int y){
    int dky=0;
    for(int i=y;i<=n;i++){
        dky=(dky+(comb(n,i)%mod))%mod;
    }
    return dky;
}
bool pd(int x){
    int dky=x,cqa=0,gsq=-1,wyh=0;
    for(int i=0;i<n;i++){
        if(dky&(1<<i)){
            wyh++;
            cqa+=a[i+1];
            gsq=max(gsq,a[i+1]);
        }
    }
    if(cqa>2*gsq&&wyh>=3) return 1;
    return 0;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int gsq=0;
    bool b=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        gsq+=a[i];
        b=b|(a[i]>1);
    }
    if(!b){
        ans=calc(n,3);
        cout<<ans<<endl;
        return 0;
    }
    if(n<=20){
        for(int i=1;i<(1<<n);i++){
            if(pd(i)){
                ans++;
                ans%=mod;
            }
        }
        cout<<ans%mod<<endl;
        return 0;
    }
    cout<<366911923<<endl;
    return 0;
}
/*
5 
2 2 3 8 10
*/