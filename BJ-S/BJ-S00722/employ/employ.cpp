#include<bits/stdc++.h>
using namespace std;
void testread(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
}
const int mod=998244353;
int n,m;
int s[510];
int c[510];
int f[18][19][(1<<18)];
int b[11];
signed main(){
    testread();
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            char ch;
            cin>>ch;
            s[i]=ch-'0';
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        if(n<=18){
            for(int i=1;i<=(1<<n)-1;i++){
                int p=(1<<n),bn=n;
                int num=0;
                while(p){
                    if(i&p)num++,b[num]=bn;
                    p>>=1,bn--;
                }
                if(num==1){
                    f[b[1]][0][i]=1;
                    //cout<<b[1]<<' '<<0<<' '<<i<<endl;
                    continue;
                }
                for(int j=1;j<=num;j++){
                    int bn=b[j];
                    if(c[bn]>0&&s[num]==1){
                            for(int l=1;l<=num;l++){
                                int bm=b[l];
                                if(l!=j){
                                    f[bn][0][i]+=f[bm][0][i^(1<<bn)];
                                    if(f[bn][0][i]>mod)f[bn][0][i]-=mod;
                                    //cout<<f[bm][0][(i^(1<<bn))]<<' '<<bm<<' '<<0<<' '<<(i^(1<<bn))<<endl;
                                }
                            }
                        }
                    for(int k=1;k<=num;k++){
                        //cout<<i<<' '<<j<<' '<<k<<' '<<s[num]<<' '<<c[bn]<<':'<<endl;
                        if(c[bn]>k&&s[num]==1){
                            for(int l=1;l<=num;l++){
                                int bm=b[l];
                                if(l!=j){
                                    //cout<<f[bm][k][(i^(1<<bn))]<<' '<<bm<<' '<<k<<' '<<(i^(1<<bn))<<endl;
                                    f[bn][k][i]+=f[bm][k][i^(1<<bn)];
                                    if(f[bn][k][i]>mod)f[bn][k][i]-=mod;
                                }
                            }
                        }else{
                            for(int l=1;l<=num;l++){
                                int bm=b[l];
                                if(l!=j){
                                    //cout<<f[bm][k-1][(i^(1<<bn))]<<' '<<bm<<' '<<k-1<<' '<<(i^(1<<bn))<<endl;
                                    f[bn][k][i]+=f[bm][k-1][i^(1<<bn)];
                                    if(f[bn][k][i]>mod)f[bn][k][i]-=mod;
                                }
                            }
                        }
                        //cout<<f[bn][k][i]<<endl;
                    }
                }
            }
            int ans=0;
            for(int i=0;i<n;i++){ans+=f[i][n-m][(1<<(n))-1];if(ans>mod)ans-=mod;}
            cout<<ans;
        }
    }
    return 0;
}

