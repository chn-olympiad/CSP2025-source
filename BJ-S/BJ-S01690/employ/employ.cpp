#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int n,m,c[10001],sum,ans=1;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    if(m==n){
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                printf("0");
                return 0;
            }
        }
        for(int i=1;i<=n;i++){
            if(c[i]<=0){
                printf("0");
                return 0;
            }
        }
        printf("1");
    }
    for(int i=1;i<=n;i++){
        if(c[i]<=0){
            sum++;
        }
    }
    if(sum>=m){
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans*=i;
        ans%=MOD;
    }
    printf("%lld",ans);
    return 0;
}
