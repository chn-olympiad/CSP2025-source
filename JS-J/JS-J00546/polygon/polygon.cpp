#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fin(s) freopen(s,"r",stdin)
#define fout(s) freopen(s,"w",stdout)
#define mo(s) s%=mod
int n,c[5050][4],a[5050],pre[5050],ans,mod=998244353;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fin("polygon.in");fout("polygon.out");
    cin>>n;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    rep(i,1,n){
        rep(j,a[i]+1,5001){
            //if(c[j][3]||c[j][2]) cout<<j<<' ';
            ans=(ans+c[j][3])%mod;
            ans=(ans+c[j][2])%mod;
        }
        //cout<<'\n';
        c[5001][2]+=c[5001][1];
        mo(c[5001][2]);
        c[5001][3]=(c[5001][3]*2)%mod;
        c[5001][3]+=c[5001][2];
        mo(c[5001][1]);
        mo(c[5001][2]);
        mo(c[5001][3]);
        for(int j=5000;j>=0;j--){
            if(c[j][3]){
                c[min(5001,j+a[i])][3]+=c[j][3],c[min(5001,j+a[i])][3]%=mod;
                //cout<<3<<' '<<j<<' '<<min(5001,j+a[i])<<' '<<c[min(5001,j+a[i])][3]<<'\n';
            }
            if(c[j][2]){
                c[min(5001,j+a[i])][3]+=c[j][2],c[min(5001,j+a[i])][3]%=mod;
                //cout<<3<<' '<<j<<' '<<min(5001,j+a[i])<<' '<<c[min(5001,j+a[i])][3]<<'\n';
            }
            if(c[j][1]){
                c[min(5001,j+a[i])][2]+=c[j][1],c[min(5001,j+a[i])][2]%=mod;
                //cout<<2<<' '<<j<<' '<<min(5001,j+a[i])<<' '<<c[min(5001,j+a[i])][2]<<'\n';
            }
        }
        c[a[i]][1]++;
        c[a[i]][1]%=mod;
        //cout<<1<<' '<<0<<' '<<a[i]<<' '<<c[a[i]][1]<<'\n';
        //cout<<0<<' '<<a[i]<<' '<<c[a[i]]<<'\n';
        //cout<<ans<<'\n'<<'\n';
    }
    cout<<ans;

    return 0;
}
//running limit time 3e8
