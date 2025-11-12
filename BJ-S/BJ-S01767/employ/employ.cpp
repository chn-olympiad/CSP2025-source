#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    cin>>s;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(m==n){
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                printf("0");
                return 0;
            }
        }
        long long ans=1;
        for(long long i=1;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        printf("%lld",ans%998244353);
    }
    else{
        long long ans=1;
        for(long long i=1;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        printf("%lld",ans%998244353);
    }
    return 0;
}
