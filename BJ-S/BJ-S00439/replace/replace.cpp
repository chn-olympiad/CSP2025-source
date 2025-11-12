#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1,K=1331,Mod=998244353;
int n,q,st[N],ed[N],pr[N*25],a[N],b[N],c[N*25],d[N*25];
string s1[N],s2[N],t1[N],t2[N];
int dmod(int p){
    return (p%Mod+Mod)%Mod;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    pr[0]=1;
    for(int i=1;i<=n;i++){
        pr[i]=pr[i-1]*K%Mod;
    }
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        for(int j=1;j<=s1[i].size();j++){
            a[i]=(a[i]*K+s1[i][j-1])%Mod;
            b[i]=(b[i]*K+s2[i][j-1])%Mod;
        }
        //    cout<<i<<':'<<a[i]<<' '<<b[i]<<'\n';
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        for(int j=1;j<=t1[i].size();j++){
            c[j]=(c[j-1]*K+t1[i][j-1])%Mod;
            d[j]=(d[j-1]*K+t2[i][j-1])%Mod;
            if(t1[i][j-1]!=t2[i][j-1]){
                ed[i]=j;
                if(!st[i])st[i]=j;
            }
            //cout<<j<<':'<<c[j]<<' '<<d[j]<<'\n';
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int r=ed[i];r<=t1[i].size();r++){
                int p=s1[j].size();
                //    cout<<p<<' '<<j<<' '<<r<<' '<<dmod(c[r]-c[r-p]*pr[p])<<' '<<a[i]<<'\n';
                if(dmod(c[r]-c[r-p]*pr[p])==a[j]&&b[j]==dmod(d[r]-d[r-p]*pr[p])){
                //    cout<<p<<' '<<j<<' '<<r<<' '<<dmod(c[r]-c[r-p]*pr[p])<<' '<<a[i]<<'\n';
                    if(r-p<st[i])ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}