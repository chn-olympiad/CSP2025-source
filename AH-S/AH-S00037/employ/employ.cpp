#include<bits/stdc++.h>
#define int long long 
#define rep(i,x,y) for(int i=x;i<=y;i++)


using namespace std;

int n,m;
bool s[514151];
const int mod=998244353;

int jc[1145141];

int f[1<<19][20];//s 状态 i 被拒绝的人数
int c[1145141];
signed main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n) {
        char cc;
        cin>>cc;
        s[i]=cc-'0';
    }
    rep(i,1,n) cin>>c[i];
    if(n<=18) {
        rep(i,1,n) {
            if(s[1]==0||c[i]==0) {
                f[1<<i-1][1]=1;
            } else {
                f[1<<i-1][0]=1;
            }
        }

    rep(i,1,n-1) {//
        for(int ns=0;ns<(1ll<<n);ns++) {//zhaungtai
            int ii=0;
            rep(ww,0,n-1) {
                if((1<<ww)&ns) ii++;
            }
            if(ii!=i) continue;
           // cout<<i<<' '<<ns<<endl;
                rep(ni,1,n) {
                    if(ns&(1ll<<ni-1)) continue;
                    //s -> s|(1<<i)
                    rep(j,0,i) {
                        if(s[i+1]==0||c[ni]<=j) {
                            //beijujue
                            f[ns|(1<<ni-1)][j+1]=(f[ns|(1<<ni-1)][j+1]+f[ns][j])%mod;
                        }else{
                            f[ns|(1<<ni-1)][j]=(f[ns|(1<<ni-1)][j]+f[ns][j])%mod;
                        }
                    }
               // }
            }

        }
    } 
        int ans=0;
        rep(i,0,n-m) ans+=f[(1ll<<n)-1][i];
        cout<<ans%mod;
    } else {
        if(m==n) {
            int fl=1;
            int jc=1;
            rep(i,1,n) jc=jc*i%mod;
            rep(i,1,n) {
                if(s[i]==0||c[i]==0) fl=0;
            }
            if(fl) cout<<jc;
            else cout<<0;
        }else {
            cout<<0;
        }
    }


    return 0;
}