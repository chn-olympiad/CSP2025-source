#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s;
int c[510],b[510];
int ans=0,ss=0;
const int mod=998244353;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int x=1;x<=n;x++){
        cin>>c[x];
        b[x]=x;
    }
    if(m==n){
        int op=1;
        for(int x=1;x<=n;x++){
            ss+=(s[x]-'0');
            if(c[x]==0)op=0;
        }
        if(ss!=n||op==0)cout<<0;
        else{
            ans=1;
            for(int x=1;x<=n;x++){
                ans=ans*x%mod;
            }
            cout<<ans;
        }
        return 0;
    }
    do{
        int nn=0;
        for(int x=1;x<=n;x++){
            if(nn>=c[b[x]]||s[x]=='0'){
                nn++;
            }
        }
        if(n-nn>=m)ans++;
    }while(next_permutation(b+1,b+n+1));
    cout<<ans<<'\n';
}
/*
3 2
101
1 1 2
*/