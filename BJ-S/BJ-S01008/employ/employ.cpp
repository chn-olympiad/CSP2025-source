#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define fr first
#define sc second
#define mk make_pair
#define pb push_back
const int MAXN=510,N=15,inf=1e9,Mod=998244353;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;}
int n,m,t,ans,a[MAXN],id[MAXN],jc[MAXN],ny[MAXN],p[MAXN];
int Pow(int x,int y){int rt=1;while(y){if(y&1)rt=rt*x%Mod;x=x*x%Mod,y>>=1;}return rt;}
int C(int x,int y){return jc[x]*ny[y]%Mod*ny[x-y]%Mod;}
void add(int &x,int y){x+=y;if(x>=Mod)x-=Mod;}
char c[MAXN];
void slv(){
    n=read(),m=read();
    scanf("%s",c+1);
    jc[0]=1;
    for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%Mod,ny[i]=Pow(jc[i],Mod-2);
    for(int i=1;i<=n;i++)if(c[i]=='1'){
        t++;
        p[t]=i-t;
    }
    if(m>t){puts("0");return;}
    if(t==n){
        printf("%d",jc[n]);
        return;
    }
    if(m==n){puts("0");return;}
    // for(int i=1;i<=n;i++)a[i]=read(),id[i]=i;
    // do{

    // }while(next_permutation(id+1,id+n+1));
    printf("%lld",ans);
}
signed main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    slv();
    cerr<<(clock()*1.0)/CLOCKS_PER_SEC<<"s\n";
    return 0;
}