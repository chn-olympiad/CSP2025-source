#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull long long
#define pb push_back
#define mk make_pair
#define fr first
#define se second
int read(){
    int n=0,fl=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') fl=-1; 
        c=getchar();
    }
    while(isdigit(c)) n=n*10+c-'0',c=getchar();
    return n*fl;
}
void write(int n){
    if(n<0) putchar('-'),n=-n;
    int c[100]={},len=0;
    while(n) c[++len]=n%10,n/=10;
    for(int i=len;i;i--) putchar(c[i]+'0');
}
void writesp(int n){write(n),putchar(' ');}
void writeln(int n){write(n),putchar('\n');}
const int mod=998244353;
int n,m,a[505],dp[1<<18][20];
bool ok[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        ok[i]=c-'0';
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==m){
        int fl=1;
        for(int i=1;i<=n;i++) if(a[i]==0) fl=0;
        for(int i=1;i<=n;i++) if(ok[i]==0) fl=0;
        if(fl){
            int ans=1;
            for(int i=1;i<=n;i++) ans=1ll*ans*i%mod;
            cout<<ans<<"\n"; 
        }
        else cout<<"0\n";
        return 0;
    }
    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if((i>>j)&1) continue;
            for(int k=0;k<=n-m;k++){
                if(k>=a[j+1]||ok[__builtin_popcount(i)+1]==0) dp[i|(1<<j)][k+1]=(dp[i|(1<<j)][k+1]+dp[i][k])%mod;
                else dp[i|(1<<j)][k]=(dp[i|(1<<j)][k]+dp[i][k])%mod;
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<=n-m;i++) ans=(ans+dp[(1<<n)-1][i])%mod;
    cout<<ans<<"\n";
    return 0;
}