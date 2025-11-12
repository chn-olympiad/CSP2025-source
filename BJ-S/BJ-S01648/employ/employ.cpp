#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],an;
long long ans;
string s;
bool isa=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    an=n;
    for(int i=0;i<n;i++){
        if(s[i]!='1'){
            isa=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            an--;
        }
    }
    if(an>n){
        printf("0");
        return 0;
    }
    if(isa){
        ans=1;
        for(long long t=2;t<=an;t++){
            ans*=t;
            ans%=998244353;
        }
        printf("%lld",ans);
        return 0;
    }
    return 0;
}
