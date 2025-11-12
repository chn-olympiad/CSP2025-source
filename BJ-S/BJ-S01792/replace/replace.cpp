#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e6+10;
const int mask=30;
const int mod=998244353;
int ans,c[maxn],n,q,d[maxn],e[maxn];
int gethash(string s){
    int n=s.size(),x=0;
    for(int i=0;i<n;i++) x=(x*mask+(s[i]-'a'))%mod;
    return x;
}
string s1[maxn],s2[maxn],t1,t2;
int x[maxn],y[maxn];
unordered_map<int,int> mp;
int getdhash(int l,int r){
    if(l>r) return 0;
    if(l==0) return d[r];
    return (d[r]-(d[l-1]*c[r-l+1])%mod+mod)%mod;
}
int getehash(int l,int r){
    if(l>r) return 0;
    if(l==0) return e[r];
    return (e[r]-(e[l-1]*c[r-l+1])%mod+mod)%mod;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    c[0]=1;
    for(int i=1;i<maxn;i++) c[i]=(c[i-1]*26)%mod;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        x[i]=gethash(s1[i]),y[i]=gethash(s2[i]);
        //mp[(x[i]-y[i]+mod)%mod]++;
        //cout<<x[i]<<" "<<y[i]<<'\n';
    }
    while(q--){
        ans=0;
        cin>>t1>>t2;
        int m=t1.size();
        for(int i=0;i<m;i++){
            if(i==0) d[i]=t1[i]-'a',e[i]=t2[i]-'a';
            else{
                d[i]=(d[i-1]*mask+t1[i]-'a')%mod;
                e[i]=(e[i-1]*mask+t2[i]-'a')%mod;
            }
        }
        for(int i=1;i<=n;i++){
            int len=s1[i].size();
            for(int j=0;j<m;j++){
                if(j+len-1>=m) break;
                //if(i==3&&j==2){
                    //cout<<(x[i])<<"HHH"<<'\n';
                //}
                if(getdhash(0,j-1)==getehash(0,j-1)&&getdhash(j,j+len-1)==x[i]&&getehash(j,j+len-1)==y[i]&&getdhash(j+len,m-1)==getehash(j+len,m-1)){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
