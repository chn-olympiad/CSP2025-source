#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans=1,mod=998244353;
string s;
long long ac(long long a,long long b){
    long long num=1;
    for(int i=a;i>=a-b+1;i--){
        num=(num*(i%mod))%mod;
    }
    return num;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cout<<1;
    cin>>s;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a!=0) sum++;
    }
    for(int i=m;i<=sum;i++){
        ans=(ans+ac(sum,i)%mod*ac(n-sum,n-sum)%mod)%mod;
    }
    cout<<ans%mod;
    return 0;
}
