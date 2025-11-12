#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005];
int n;
int dfs(int x,int y,int k,int j,int i){
    for(int z=y;z>=1;z--){
        if(a[z]>(a[i]-a[j]-a[k])){
            x=x+z%mod;
            x%=mod;
            return x;
        }else{
            if(a[z]==(a[i]-a[j]-a[k])){
                x=x+(z-1)%mod;
                x%=mod;
                return x;
            }else dfs(x,z-1,k,j,i);
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=n;i>=3;i--){
        for(int j=i-1;j>=2;j--){
            for(int k=j-1;k>=1;k--){
                if(a[i]*2<a[j]+a[k]+a[i]){
                    ans=ans%mod+k%mod;
                    ans%=mod;
                    break;
                }else{
                    if(a[i]*2==a[j]+a[i]+a[k]){
                        ans=ans%mod+(k-1)%mod;
                        ans%=mod;
                        break;
                    }else{
                        ans=ans+dfs(0,k-1,k,j,i);
                        /*for(int z=k-1;z>=1;z--){
                            if(a[z]>(a[i]-a[j]-a[k])){
                                ans=ans+(z-1)%mod;
                                ans%=mod;
                                break;
                            }
                        }*/
                    }
                }
            }
        }
    }
    ans%=mod;
    cout<<ans*1.5<<endl;
    return 0;
}
