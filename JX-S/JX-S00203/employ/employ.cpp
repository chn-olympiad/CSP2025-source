#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define INF 1e9
#define LLINF 1e18
#define ll long long
#define Mod 998244353
#define FILE1(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define FILE2(x) freopen(x".in","r",stdin),freopen(x".ans","w",stdout)
#define FILE3(x) freopen(x".in","r",stdin)
using namespace std;
int read(){
    int x=0,f=1,ch=getchar();
    for(;!isdigit(ch);ch=getchar()) f=(ch=='-')?-1:1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
    return x*f;
}
int add(int x,int y){return x+y>=Mod?x+y-Mod:x+y;}
int del(int x,int y){return add(x,Mod-y);}
int mul(int x,int y){return ((ll)x*y)%Mod;}
void Add(int &x,int y){x=add(x,y);}
void Del(int &x,int y){x=del(x,y);}
void Mul(int &x,int y){x=mul(x,y);}
int n,m;
namespace Subtask1{
    #define N 20
    #define S 262144
    #define Mod 998244353
    string st;
    int c[N],f[S][N],ans;
    bool check(int x,int base){return x>>base&1;}
    void Main(){
        cin>>st;st=" "+st;
        for(int i=1;i<=n;++i) c[i]=read();
        f[0][0]=1;
        for(int s=0;s<(1<<n);++s){
            for(int i=0;i<=__builtin_popcount(s);++i){
                if(!f[s][i]) continue;
                for(int j=1;j<=n;++j){
                    if(check(s,j-1)) continue;
                    if(c[j]<=i || st[__builtin_popcount(s)+1]=='0') Add(f[s|(1<<j-1)][i+1],f[s][i]);
                    else Add(f[s|(1<<j-1)][i],f[s][i]);
                }
            }
        }
        for(int i=0;i<=n-m;++i) Add(ans,f[(1<<n)-1][i]);
        printf("%d",ans);
    }
}
int main(){
    FILE1("employ");
    n=read(),m=read();
    if(n<=18) Subtask1::Main();
    else if(n==m){
        string s;cin>>s;
        bool ok=true;
        for(int i=1;i<=n;++i) ok&=(s[i]=='1');
        for(int i=1;i<=n;++i){
            int x=read();
            if(!x) ok=false;
        }
        if(!ok) puts("0");
        else{
            int ans=1;
            for(int i=1;i<=n;++i) Mul(ans,i);
            printf("%d",ans);
        }
    }
    return 0;
}