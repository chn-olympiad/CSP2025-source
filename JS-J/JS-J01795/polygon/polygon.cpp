#include<bits/stdc++.h>
using namespace std;
const int N=5010;
#define mod 998244353
long long n,a[N],ma=-1,k=0,ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    ma=1;
   for(int i=1;i<=n;i++){
        cin>>a[i];
        k+=a[i];
        ma=max(a[i],ma);
    }
    if(n==3){
        if(k>ma*2){
            cout<<1;
        }
        else{
          cout<<0;
        }
        return 0;
    }
    else if(ma==1&&n<=500){
        long long  p=n*(n-1)*(n-2);
        ans=0;
        ans+=p;
        p%=mod;
        ans%=mod;
        for(int i=n-3;i>=1;i--){
            p=p*i;
            //p%=mod;
            ans+=p;
            ans%=mod;
        }
        cout<<ans%mod;
        return 0;
    }
    else if(n==4){
        int s=k;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int x=j+1;x<=n;x++){
                    s=s-(a[i]+a[j]+a[x]);
                    ma=max(a[i],max(a[j],a[x]));
                    if(ma*2<a[i]+a[j]+a[x]){
                        ans++;
                    }
                }
            }
        }
        ma=max(a[1],max(a[2],max(a[3],a[4])));
        if(ma*2<a[1]+a[2]+a[3]+a[4]){
            ans++;
        }
        cout<<ans;
    }
    else if(n==5){
        int s=k;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int x=j+1;x<=n;x++){
                    s=s-(a[i]+a[j]+a[x]);
                    ma=max(a[i],max(a[j],a[x]));
                    if(ma*2<a[i]+a[j]+a[x]){
                        ans++;
                    }
                    for(int y=x+1;y<=n;y++){
                        ma=max(a[i],max(a[j],max(a[x],a[y])));
                        if(ma*2<a[i]+a[j]+a[x]+a[y]){
                            ans++;
                        }
                    }
                }
            }
        }
        ma=max(a[1],max(a[2],max(a[3],max(a[4],a[5]))));
        if(ma*2<a[1]+a[2]+a[3]+a[4]+a[5]){
            ans++;
        }
        cout<<ans;
    }

    return 0;
}
