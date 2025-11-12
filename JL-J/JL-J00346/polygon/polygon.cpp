#include<bits/stdc++.h>
using namespace std;
const long long N=5e3+10,MOD=998244353;
long long n,he,wei[N],ii,a[N],ma,ejz,ans,zc,P1,s1;
long long ksm(long long a,long long b,long long p){
    ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        b>>=1;
    }
    return ans%p;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=1){
            P1=1;
        }
    }
    if(P1==0){
        ans=ksm(2,n,MOD)-1-n;
        for(int i=1;i<n;i++){
            zc=(zc+i)%MOD;
        }
        ans=(ans-zc)%MOD;
        cout<<zc;
        return 0;
    }
    ejz=ksm(2,n,MOD);
    ans=0;
    for(long long i=0;i<=ejz;i++){
        zc=i;
        ii=0;
        while(1){
            if(zc<=0){
                break;
            }
            ii++;
            wei[ii]=zc%2;
            if(wei[ii]==1){
                s1++;
            }
            zc=zc/2;
        }
        ma=0;
        he=0;
        if(s1>=3){
            for(int j=1;j<=ii;j++){
                if(wei[j]==1){
                    ma=max(ma,a[j]);
                    he=he+a[j];
                }
            }
            if(he>2*ma){
                ans++;
                ans=ans%MOD;
            }
        }
    }
    cout<<ans%MOD;
    return 0;
}
