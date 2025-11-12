#include<bits/stdc++.h>
using namespace std;
const long long N=505,MOD=998244353;
long long n,m,cnt=0,ans=0,s[N],c[N];
long long C(long long n,long long m){
    long long ans1=1,ans2=1;
    for(int i=n;i>=n-m+1;i--){
        ans1*=i;
        ans1=(ans1+MOD)%MOD;
    }
    for(int i=m;i>=1;i--){
        ans2*=i;
        ans2=(ans2+MOD)%MOD;
    }
    ans1+=MOD;
    return ans1/ans2;
}
long long f(long long x){
    long long ans=1;
    for(int i=x;i>=1;i--){
        ans*=i;
        ans=(ans+MOD)%MOD;
    }
    return ans;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char op;
        cin>>op;
        s[i]=int(op-'0');
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n==m){
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(s[i]==0||c[i]==0){
                flag=0;
                break;
            }
        }
        if(flag==0) cout<<0;
        else{
            int ans=1;
            for(int i=n;i>=1;i--){
                ans*=i;
                ans%=MOD;
            }
            cout<<ans%MOD;
        }
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(c[i]==0) cnt++;
    }
    cout<<C(n,cnt)*f(n-cnt);
    return 0;
}
