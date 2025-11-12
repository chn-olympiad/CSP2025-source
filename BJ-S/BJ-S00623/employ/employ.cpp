#include<iostream>
using namespace std;

const int P=998244353;
const int N=510;
int s[N],c[N];
int f[(1<<18)][19];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) {
        char c;cin>>c;
        if(c=='0') s[i]=0;
        else s[i]=1;
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n<=18) {
        f[0][0]=1;
        for(int i=0;i<=(1<<n)-1;i++) {
            int cnt=__builtin_popcount(i);
            for(int j=0;j<=cnt;j++) {
                // cout<<i<<' '<<j<<' '<<f[i][j]<<' '<<cnt<<endl;
                for(int k=1;k<=n;k++) {
                    if(i&(1<<(k-1))) continue;
                    // cout<<"->"<<k<<' '<<c[k]<<endl;
                    if(s[cnt+1]==0) (f[i+(1<<(k-1))][j]+=f[i][j])%=P;
                    else {
                        // cout<<"->"<<k<<' '<<c[k]<<endl;
                        if(cnt-j>=c[k]) (f[i+(1<<(k-1))][j]+=f[i][j])%=P;
                        else (f[i+(1<<(k-1))][j+1]+=f[i][j])%=P;
                    }
                }
            }
        }
        int sum=0;
        for(int i=m;i<=n;i++) (sum+=f[(1<<n)-1][i])%=P;
        cout<<sum<<endl;
    }
    else cout<<0<<endl;
    return 0;
}