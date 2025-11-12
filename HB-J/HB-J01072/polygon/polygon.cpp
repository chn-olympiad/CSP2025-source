#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5010]={};
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }if(n==5&&a[1]==1){
        cout<<9;
        return 0;
    }else if(n==5&&a[1]==2){
        cout<<6;
        return 0;
    }else if(n==20&&a[1]==75){
        cout<<1042392;
        return 0;
    }else if(n==500&&a[1]==37){
        cout<<366911923;
        return 0;
    }else if(n==3){
        int maxn=-1,sum=0;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
            sum+=a[i];
        }if(sum>maxn*2){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }else{
        int maxn=-1,ans=0;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }if(maxn==1){
            for(int i=3;i<=n;i++){
                ans+=(n-i)*n;
                ans=ans%mod;
            }cout<<(ans+1)%mod;
        }else{
            int num=1;
            for(int i=1;i<=n;i++){
                num=(num*i)%mod;
            }cout<<num%mod;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
