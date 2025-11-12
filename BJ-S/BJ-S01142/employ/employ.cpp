#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt,mod=998244353,ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
   cin>>n>>m>>s;
   int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x==0)cnt++;
    }
    //cout<<cnt;
    if(m+cnt>n)cout<<0;
    else{
        n-=cnt;//m-=cnt;
        ans=1;
        for(int i=n-m+1;i<=n;i++){
            ans=ans*i%mod;    
        }
        for(int i=1;i<=m;i++){
            ans=(long long)(double(ans)*pow(i,-1))%mod;    
        }
        //for(int i=1;i<=n;i++)ans=ans*i%mod;
        cout<<ans;
    }
    return 0;
}
