#include<bits/stdc++.h>
#define N 2005
#define int long long
using namespace std;
const int base=13331;
const int mod=1e9+19260817;
int n,q;string s[N][3],t[N][3];
int hs[N][N][3],ht[N][N][3],ans;
int mi(int a,int b){
    int ss=1;
    while(b){
        if(b&1)ss=ss*a%mod;
        a=a*a%mod;b>>=1;
    }return ss;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
    for(int i=1;i<=q;i++)cin>>t[i][1]>>t[i][2];
    for(int i=1;i<=n;i++){
        for(int j=0;j<s[i][1].size();j++){
            if(!j){
                hs[i][j][1]=s[i][j][1]%mod;
                hs[i][j][2]=s[i][j][2]%mod;
            }else{
                hs[i][j][1]=(hs[i][j-1][1]*base+s[i][j][1])%mod;
                hs[i][j][2]=(hs[i][j-1][2]*base+s[i][j][2])%mod;
            }
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=0;j<t[i][1].size();j++){
            if(!j){
                ht[i][j][1]=t[i][j][1]%mod;
                ht[i][j][2]=t[i][j][2]%mod;
            }else{
                ht[i][j][1]=(ht[i][j-1][1]*base+t[i][j][1])%mod;
                ht[i][j][2]=(ht[i][j-1][2]*base+t[i][j][2])%mod;
            }
        }
    }
    for(int i=1;i<=q;i++){ans=0;
        for(int j=1;j<=n;j++){
            for(int j=0;j<t[i][1].size();j++){
                int len=s[j][1].size();
                int nxt=j+len-1;
                int bbc=ht[i][j][1]*mi(base,len-1)%mod;
                if(ht[i][nxt][1]-bbc==hs[i][len][1]){
                    int bbd=ht[i][j][2]*mi(base,len-1)%mod;
                    if(ht[i][nxt][2]-bbd==hs[i][len][2])ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }return 0;
}
