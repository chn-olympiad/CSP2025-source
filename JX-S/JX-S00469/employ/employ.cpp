#include<cstring>
#include<iostream>
using namespace std;
const long long mod=998244353;
long long n,m;
string s;
long long a;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    bool p1=true;
    for(int i=0;i<s.size();i++){
        if(s[i]!='1'){
            p1=false;
        }
    }
    if(p1){
        long long u=1;
        long long y=n-m+1;
        while(1){
            if(y!=0){
                u*=y;
            }else{
                break;
            }
            y--;
            u%=mod;
        }
        cout<<u%mod;
        return 0;
    }
    long long y=1;
    long long sum=0;
    for(int i=s.size()-1;i>=0;i--){
        sum+=(s[i]-'0')*y;
        y*=2;
        sum%=mod;
    }
    for(int i=1;i<=n;i++){
        cin>>a;
        sum-=a;
        sum%=mod;
    }
    cout<<1ll*sum%mod*m%mod;
    return 0;
}
