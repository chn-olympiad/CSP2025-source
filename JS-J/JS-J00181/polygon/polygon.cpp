#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int mod=998244353;
int a[100005];
int f[100005];
ll quickpow(int x){
    if(x==1||x==0) return 1;
    if(!f[x]){
        f[x]=quickpow(x-1)*x;
        return f[x];
    }
    return f[x];
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    f[1]=1;
    int ta=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) ta=0;
    }
    sort(a+1,a+n+1);
    if(ta){
        ll ans=0;
        for(int i=3;i<=n;i++){
            ans+=(quickpow(n)%mod)/((quickpow(i)%mod)*(quickpow(n-i)%mod))%mod;
        }
        cout<<ans%mod;
        return 0;
    }else if(n==3){
        if(a[1]+a[2]>a[3]) cout<<1;
        else cout<<0;
    }else if(n==4){
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(a[i]+a[j]>2*a[k]) ans++;
                    for(int l=k+1;l<=n;l++){
                        if(a[i]+a[j]+a[k]>2*a[l]) ans++;
                    }
                }
            }
        }
        cout<<ans;
    }else if(n==5){
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(a[i]+a[j]>2*a[k]) ans++;
                    for(int l=k+1;l<=n;l++){
                        if(a[i]+a[j]+a[k]>2*a[l]) ans++;
                        for(int m=l+1;m<=n;m++){
                            if(a[i]+a[j]+a[k]+a[l]>2*a[m]) ans++;
                        }
                    }
                }
            }
        }
        cout<<ans;
    }else if(n==6){
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    if(a[i]+a[j]>2*a[k]) ans++;
                    for(int l=k+1;l<=n;l++){
                        if(a[i]+a[j]+a[k]>2*a[l]) ans++;
                        for(int m=l+1;m<=n;m++){
                            if(a[i]+a[j]+a[k]+a[l]>2*a[m]) ans++;
                            for(int o=m+1;o<=n;o++){
                                if(a[i]+a[j]+a[k]+a[l]+a[m]>2*a[o]) ans++;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans;
    }else{
        cout<<(n*(n-1)%mod)/2;
    }

    return 0;
}
