#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,mod=998244353,M=20;
int n,m,s[N],c[N];
ll ff[270000][20];
string o;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>o;
    for(int i=1;i<=n;i++){
        s[i]=o[i-1]-'0';
    }
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    if(n<=18){
        ff[0][0]=1;
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<=n;j++){
                int len=0;
                for(int k=1;k<=n;k++){
                    if(i&(1<<(k-1))){
                        len++;
                    }
                }
                for(int k=1;k<=n;k++){
                    if(i&(1<<(k-1))){
                        if(s[len]&&len-1-max(0,(j-1))<c[k]){
                            if(j)ff[i][j]+=ff[i^(1<<(k-1))][j-1];
                        }
                        else if(!s[len]||len-1-j>=c[k])ff[i][j]+=ff[i^(1<<(k-1))][j];
                    }
                    ff[i][j]%=mod;
                }
            }
        }
        ll ans=0;
        for(int i=m;i<=n;i++){
            ans=(ans+ff[(1<<n)-1][i])%mod;
        }
        printf("%lld",ans);
    }
    return 0;
}
