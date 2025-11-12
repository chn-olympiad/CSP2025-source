#include <cstdio>
#include <cstring>
#define ll long long
#define mod1 1000000007
#define mod2 998244353
#define base 31
using namespace std;
/*char S[5000005];
int hash1[5000005];
int hash2[5000005];
int S_cnt;
struct String{
    int ks;
    int jw;
};
String s[200005][2];//0,1*/
char s[1005][2][2005];
int shash1[1005][2];
int shash2[1005][2];
int p1[2005];
int p2[2005];
ll f[2005];
char t[2][2005];
int thash1[2][2005];
int thash2[2][2005];
int n,q;
bool xd(int tb,int bbh,int bb,int l,int r){
    if(l<=0){
        return false;
    }
    int len=(r-l)+1;
    if((thash1[tb][r]-1ll*thash1[tb][l-1]*p1[len]%mod1)%mod1==shash1[bbh][bb]){
        if((thash2[tb][r]-1ll*thash2[tb][l-1]*p2[len]%mod2)%mod2==shash2[bbh][bb]){
            return true;
        }
    }
    return false;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%s%s",s[i][0]+1,s[i][1]+1);
        int len=strlen(s[i][0]+1);
        for(int j=1;j<=len;j++){
            shash1[i][0]=(1ll*shash1[i][0]*base%mod1+s[i][0][j]-'a')%mod1;
        }
        for(int j=1;j<=len;j++){
            shash2[i][0]=(1ll*shash2[i][0]*base%mod2+s[i][0][j]-'a')%mod2;
        }
        for(int j=1;j<=len;j++){
            shash1[i][1]=(1ll*shash1[i][1]*base%mod1+s[i][1][j]-'a')%mod1;
        }
        for(int j=1;j<=len;j++){
            shash2[i][1]=(1ll*shash2[i][1]*base%mod2+s[i][1][j]-'a')%mod2;
        }
    }
    while(q--){
        scanf("%s%s",t[0]+1,t[1]+1);
        int len=strlen(t[0]+1);
        p1[0]=1;
        p2[0]=1;
        for(int i=1;i<=len;i++){
            p1[i]=1ll*p1[i-1]*base%mod1;
            p2[i]=1ll*p2[i-1]*base%mod2;
            thash1[0][i]=(1ll*thash1[0][i-1]*base%mod1+t[0][i-1]-'a')%mod1;
            thash2[0][i]=(1ll*thash2[0][i-1]*base%mod2+t[0][i-1]-'a')%mod2;
            thash1[1][i]=(1ll*thash1[1][i-1]*base%mod1+t[1][i-1]-'a')%mod1;
            thash2[1][i]=(1ll*thash2[1][i-1]*base%mod2+t[1][i-1]-'a')%mod2;
        }
        f[0]=1;
        for(int i=1;i<=len;i++){
            if(t[0][i]==t[1][i]){
                f[i]+=f[i-1];
            }
            for(int j=1;j<=n;j++){
                int slen=strlen(s[j][0]+1);
                if(xd(1,j,1,i-slen+1,i) && xd(0,j,0,i-slen+1,i)){
                    f[i]+=f[i-slen];
                }
            }
        }
        printf("%lld\n",f[len]);
    }
    //for(int )
    return 0;
}