#include <bits/stdc++.h>
using namespace std;
#define LL long long

#define N 270000
#define mod 998244353
vector<int>st[20];

#define L 507
char s[L];
int c[20],f[N][20];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<(1<<n);i++) st[__builtin_popcount(i)].push_back(i);
    cin>>s;
    for(int i=0;i<n;i++) cin>>c[i];

    for(int i=1;i<=n;i++)
        for(int j=0;j<(int)st[i].size();j++){//1的个数为i的状态（第i天）
            int mask=st[i][j];
            for(int k=0;k<=i;k++)//通过面试的人数
                for(int x=0;x<n;x++)//今天的受试者
                    if((mask>>x)&1){
                        if(i==1){
                            if(!c[x]) f[mask][0]=1;
                            else f[mask][s[0]^48]=1;
                            continue;
                        }
                        if(!(s[i-1]^48)) f[mask][k]=(f[mask][k]+f[mask^(1<<x)][k])%mod;
                        else{
                            if(c[x]>i-k) f[mask][k]=(f[mask][k]+f[mask^(1<<x)][k-1])%mod;
                            if(c[x]<=i-1-k) f[mask][k]=(f[mask][k]+f[mask^(1<<x)][k])%mod;
                        }
                    }
        }
    /*for(int i=1;i<=n;i++)
        for(int j=0;j<(int)st[i].size();j++){
            cout<<st[i][j]<<' ';
            for(int k=0;k<=i;k++) cout<<f[st[i][j]][k]<<' ';
            cout<<'\n';
        }*/
    int Ans=0;
    for(int i=m;i<=n;i++) Ans=(Ans+f[(1<<n)-1][i])%mod;
    cout<<Ans<<'\n';

    return 0;
}
/*
g++ -Wall employ.cpp -o employ
./employ
*/