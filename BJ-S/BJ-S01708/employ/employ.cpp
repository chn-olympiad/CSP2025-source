#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
const int mod=998244353;

namespace OOO{
    const int N=22;
    int n,m,p[N],c[N],f[2][19][1<<18];
    string s;

    void zhuang(int NN,int MM){
        n=NN,m=MM;
        cin>>s;_for(i,1,n) cin>>c[i];
        f[0][0][0]=1;
        _for(i,0,n-1){
            int nw=i&1,nxt=(i+1)&1;
            memset(f[nxt],0,sizeof f[nxt]);
            _for(j,0,i){
                _rep(S,0,(1<<n)){
                   // if(i==2&&j==1&&S==3){
                 //       cout<<f[i&1][j][S]<<'\n';
                 //   }
                    _rep(k,0,n){
                        if(!((1<<k)&S)){
                            int T=S^(1<<k);
                            //nxt 填 (k+1)
                            int add=0;
                            if(s[i]=='0') add=1;
                            if(j>=c[k+1]) add=1;
                          //  if(i+1==n){
                          //      cout<<j+add<<' '<<T<<' '<<f[nw][j][S]<<'\n';
                           // }
                            f[nxt][j+add][T]=(f[nxt][j+add][T]+f[nw][j][S])%mod;
                            //f[nxt][]
                        }
                    }
                }
            }
        }
        int nn=n&1,ans=0;
        _for(i,nn,nn){
            _for(j,0,n-m){
               // cout<<j<<'!';
                _rep(S,0,(1<<n)){
                    ans=(ans+f[i][j][S])%mod;
                }
            }
        }
        cout<<ans<<'\n';
    }
}

namespace O_{
    const int N=22;
    int n,m,p[N],c[N],f[2][19][1<<18];
    string s;

    void zhuang(int NN,int MM,string sq){
        n=NN,m=MM;s=sq;
        _for(i,1,n) cin>>c[i];
        f[0][0][0]=1;
        _for(i,0,n-1){
            int nw=i&1,nxt=(i+1)&1;
            memset(f[nxt],0,sizeof f[nxt]);
            _for(j,0,i){
                _rep(S,0,(1<<n)){
                   // if(i==2&&j==1&&S==3){
                 //       cout<<f[i&1][j][S]<<'\n';
                 //   }
                    _rep(k,0,n){
                        if(!((1<<k)&S)){
                            int T=S^(1<<k);
                            //nxt 填 (k+1)
                            int add=0;
                            if(s[i]=='0') add=1;
                            if(j>=c[k+1]) add=1;
                          //  if(i+1==n){
                          //      cout<<j+add<<' '<<T<<' '<<f[nw][j][S]<<'\n';
                           // }
                            f[nxt][j+add][T]=(f[nxt][j+add][T]+f[nw][j][S])%mod;
                            //f[nxt][]
                        }
                    }
                }
            }
        }
        int nn=n&1,ans=0;
        _for(i,nn,nn){
            _for(j,0,n-m){
               // cout<<j<<'!';
                _rep(S,0,(1<<n)){
                    ans=(ans+f[i][j][S])%mod;
                }
            }
        }
        cout<<ans<<'\n';
    }

}

namespace Ofac{
    int n,m,p[15],c[15];
    string s;
    void bf(int NN,int MM){
        n=NN,m=MM;
        _for(i,1,n) p[i]=i;
        cin>>s; _for(i,1,n) cin>>c[i];
        int cnt=0;
        do{
            int ct=0,sum=0;
            _for(i,1,n){
                if(s[i-1]=='1'&&sum<c[p[i]]) ct++;
                else sum++;
//                sum+=(s[i-1]=='0');
            }
            if(ct>=m) cnt++;
            //cout<<ct<<':'<<'\n';
            //_for(i,1,n) cout<<p[i]<<' ';
            //cout<<'\n';
        }while(next_permutation(p+1,p+n+1));
        cout<<cnt<<'\n';
    }
}

namespace zcy{
    const int N=505;
    int n,m,p[N],c[N];
    string s;
    void M_1(int NN,int MM){
        int all=1;
        n=NN,m=MM;
        cin>>s;
        int c0=0,fac=1;
        for(auto i:s) c0+=(i=='0');
        _for(i,1,c0) fac=(1ll*fac*i)%mod;
        _for(i,1,n) cin>>c[i],all=(1ll*all*i)%mod;
        sort(c+1,c+n+1);
        int lun=0,sum=0,qwq=1;
        _for(i,1,n){
            if(s[i-1]=='0') continue;
            sum=0;
            _for(j,1,n) if(c[j]<=i-1) sum++ ;
            //cout<<sum<<' ';
            sum-=lun;
            if(sum<=0) qwq=0;
            else qwq=1ll*qwq*sum%mod;
            //cout<<qwq<<'\n';
            lun++;
        }
        //cout<<qwq<<' ';
        qwq=(1ll*qwq*fac)%mod;
        //cout<<all<<'\n';
        cout<<(all-qwq+mod)%mod<<'\n';
    }
}


int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    //96
    if(n<=10) Ofac::bf(n,m),exit(0);
    if(n<=18) OOO::zhuang(n,m),exit(0);

    if(m==1){
        zcy::M_1(n,m);
        exit(0);
    }
    if(n==m){
        string s;cin>>s;
        int F=1;
        _for(i,1,n){
            int x;cin>>x;
            if(x==0) F=0;
        }
        for(auto i:s){
            if(i=='0') F=0;
        }
        int fac=1;
        _for(i,1,n){
            fac=(fac*i)%mod;
        }
        cout<<fac*F<<'\n';
        exit(0);
    }
    string s;
    cin>>s;
    int cnt=0;
    for(auto i:s) cnt+=(i=='1');
    if(cnt<=18){
        O_::zhuang(n,m,s);
    }
    return 0;
}
