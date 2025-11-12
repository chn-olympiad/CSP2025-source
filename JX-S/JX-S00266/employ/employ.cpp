#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550,mod=998244353;
int n,m,ans,ks;
int c[N],s[N];
int v[N],p[N],in[N];
map<int,int>mp;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    in[0]=1;
    for(int i=1;i<=n+5;i++){
        in[i]=in[i-1]*i%mod;
    }
    bool ff=1;
    for(int i=1;i<=n;i++){
        char x;
        cin>>x;
        s[i]=x-'0';
        if(s[i]==0){
            ff=0;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0)ks++;
        mp[c[i]]++;

    }
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    int res=1;
    for(auto [x,y]:mp){
        res=res*in[y]%mod;
    }
    sort(c+1,c+1+n);
    do{
        int fq=0,ky=0;
        for(int i=1;i<=n;i++){
            if(c[p[i]]<=fq)fq++;
            else {
                if(s[i]==0)fq++;
                else ky++;
            }
        }
        if(ky>=m){
            ans++;
            ans=ans%mod;
        }
    }while(next_permutation(c+1,c+1+n));
    cout<<ans*res%mod;
    return 0;
}
