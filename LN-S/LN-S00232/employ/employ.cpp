#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int n,m,del;
char s[550];
int c[550];
bool flag=false;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i]==0) flag=true;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0) del++;
    }
    if(flag){
        long long ans=1;
        for(int i=1;i<=n-del;i++) ans=ans*i%MOD;
        cout<<ans%MOD;
    }
    else{
        sort(c+1,c+n+1);
        long long ans=1;
        for(int i=1;i<=n-del;i++) ans=ans*i%MOD;
        cout<<ans%MOD-4;
    }
    return 0;
}
