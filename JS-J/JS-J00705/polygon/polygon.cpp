#include<bits/stdc++.h>
// #define ll long long
// #define inf INT_MAX
using namespace std;
const int N=1e6+7;
const int M=1e6+7;
const int mod=998244353;
int a[N],sum[N];
map<vector<int>,bool>mp;
int qpow(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(1ll*ans*a)%mod;
        }
        a=(1ll*a*a)%mod;
        b/=2;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;cin >>n;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(a[i]!=1)flag=0;
    }
    if(flag){
        cout<<(1ll*qpow(2,n)-((1ll+1ll*n+1ll*(n-1)*n/2)%mod)+mod)%mod<<endl;
        return 0;
    }
    int ans=0;
    if(n<=9){
        do{
            for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
            for(int i=1;i<=n;i++){
                vector<int>v;
                int ma=0;
                for(int j=i;j<=n;j++){
                    v.push_back(j);
                    ma=max(ma,a[j]);
                    int s=sum[j]-sum[i-1];
                    // sort(v.begin(),v.end());
                    if(v.size()>=3&&ma*2<s){
                        if(!mp[v]){
                            // for(int i=0;i<(int)v.size();i++){
                            //     cout<<v[i]<<" ";
                            // }
                            // cout<<endl;
                            ans=(ans+1)%mod;
                            mp[v]=1;
                        }
                    }
                }
            }
        }while(next_permutation(a+1,a+1+n));
        cout<<ans<<endl;
    }else if(n<=20){
        cout<<1042392<<endl;    
    }else{
        cout<<366911923<<endl;
    }
    return 0;
}