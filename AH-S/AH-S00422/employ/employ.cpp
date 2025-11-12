#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<time.h>
#define mod 998244353
#define ll long long
#define itn int
#define scf scanf
#define prf printf
#define gc getchar
#define pc putchar
#define fu(v,s,e) for(int v=s;v<=(e);v++)
#define fd(v,s,e) for(int v=s;v>=(e);v--)
using namespace std;
int _t;
inline int in(){
    itn x=0,f=1;
    char c=gc();
    while((c<'0'||c>'9')&&c!='-') c=gc();
    if(c=='-') f=-1,c=gc();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
    return f*x;
}
void out(int x){
    if(x>9) out(x/10);
    pc(x%10+'0');
}
inline void out(int x,char c){
    out(x),pc(c);
}
int n,m,c[505],frac[505];
char s[505];
namespace n18{
    int f[20][1<<18];
    int dfs(int k,int t,int s){
        if(s==m) return frac[n-k+1];
        if(k>n) return 0;
        if(f[s][t]!=-1) return f[s][t];
        ll res=0;
        fu(i,1,n){
            int dt=1<<(i-1);
            if(dt&t) continue;
            res+=dfs(k+1,t|dt,s+::s[k]*(c[i]>k-s-1));
        }
        return f[s][t]=res%mod;
    }
    void mian(){
        memset(f,-1,sizeof(f));
        out(dfs(1,0,0),'\n');
    }
}
class Thing{
    public:
    int value;
    Thing(){value=0;}
}me;
class World{
    public:
    void execute(Thing sth){
        exit(sth.value);
    }
}world;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    // _t=in();
    // while(_t--){
    // }
    frac[0]=1;
    fu(i,1,500) frac[i]=1ll*frac[i-1]*i%mod;
    n=in(),m=in();
    // fu(i,1,n) a[i]=in();
    scf("%s",s+1);
    fu(i,1,n) c[i]=in(),s[i]-='0';
    if(n<=18) n18::mian();
    else;
    // cerr<<'\n'<<clock()/1000.0<<"ms\n";
    world.execute(me);
}