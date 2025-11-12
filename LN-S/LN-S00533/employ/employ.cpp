#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int c[1000006];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,F = 0;
    cin>>n>>m;
    string s;cin>>s;
    int ling = 0;
    for(int i = 1;i<=n;i++){
        if(s[i]!='1'){
            F = 1;
            ling++;
        }
    }
    for(int i = 1;i<=n;i++) cin>>c[i];
    sort(c+1,c+1+n);
    if(!F){
        long long ans = 1;
        for(long long i = 1;i<=n;i++){
            ans = (ans%mod)*(i%mod)%mod;
        }
        cout<<ans<<endl;
    }else{
        int k = n-ling;
        long long num1 = 1,num2 = 1;
        for(int i = 1;i<=n;i++) num1 = num1*i%mod;
        for(int i = 1;i<=n-k;i++) num2 = num2*i%mod;
        long long ans = num1/num2;
        cout<<ans-k<<endl;
    }
    return 0;
}
