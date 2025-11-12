#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string lev;
int p[505];
long long ans=1;
int mul[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>lev;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    mul[1]=1;
    for(int i=2;i<=n;i++){
        mul[i]=mul[i-1]*i;
        mul[i]%=mod;
    }
    if(m==1){
        sort(p+1,p+n+1);
        int k,cnt=0;
        int one=0;
        for(int i=0;i<n;i++){
            if(lev[i]=='0'){
                k=i;
                for(int i=n;i>=1;i--){
                    if(p[i]<=k-one){
                        break;
                    }
                    cnt++;
                }
                ans+=(cnt*mul[n-1])%mod;
                ans%=mod;
                cnt=0;
                one++;
            }
        }
    }else{
        ans=mul[n];
    }
    cout<<ans;
    return 0;
}
