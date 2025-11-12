#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr ll modd=998244353;
ll n,m,c[505];
char ch[505];
namespace cod2{
    ll dp[(1<<18)][20];
    void work(){
        dp[0][0]=1;
        for(int s=0;s<(1<<n);s++){
            int cur=__builtin_popcount(s);
            for(int j=0;j<=cur;j++){
                for(int k=1;k<=n;k++){
                    if((~s)&(1<<(k-1))){
                        //place k
                        if(cur-1-j>=c[k] || ch[cur+1]=='0'){
                            dp[s^(1<<(k-1))][j]=(dp[s][j]+dp[s^(1<<(k-1))][j])%modd;
                        }else{
                            dp[s^(1<<(k-1))][j+1]=(dp[s][j]+dp[s^(1<<(k-1))][j+1])%modd;
                        }
                    }
                }
            }
        }
        ll ans=0;
        for(int i=m;i<=n;i++){
            ans=(ans+dp[(1<<n)-1][i])%modd;
        }
        cout<<ans<<"\n";
    }
};
namespace cod1{
    ll id[15];
    void work(){
        for(int i=1;i<=n;i++){
            id[i]=i;
        }
        ll ans=0;
        do{
            ll lu=0;
            for(int i=1;i<=n;i++){
                if(ch[i]=='0')continue;
                if(i-1-lu>=c[id[i]])continue;
                lu++;
            }
            if(lu>=m)ans++;
        }while(next_permutation(id+1,id+n+1));
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>(ch+1);
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(n<=10)cod1::work();
    else cod2::work();
    return 0;
}