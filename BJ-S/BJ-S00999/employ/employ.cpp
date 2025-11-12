#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pow power
using namespace std;
template<typename T>void read(T &x)
{
    x=0;
    int fl=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=fl;
}
template<typename T>void write(T x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
void read(char &x){do{x=getchar();}while(!isalpha(x));}
template<typename T>void writesp(T x){write(x);putchar(' ');}
template<typename T>void writeln(T x){write(x);putchar('\n');}
const int N=505,mod=998244353;
int pls(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int mns(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1ll*x*y%mod;}
int pow(int x,int k)
{
    int res=1;
    while(k)
    {
        if(k&1) res=mul(res,x);
        x=mul(x,x);
        k>>=1;
    }
    return res;
}
int fac[N],invfac[N];
void init()
{
    fac[0]=1;
    for(int i=1;i<=N-5;i++) fac[i]=mul(fac[i-1],i);
    invfac[N-5]=pow(fac[N-5],mod-2);
    for(int i=N-5;i>=1;i--) invfac[i-1]=mul(invfac[i],i);
}
int C(int m,int n)
{
    if(n<0||n>m) return 0;
    return mul(fac[m],mul(invfac[n],invfac[m-n]));
}
int A(int m,int n)
{
    if(n<0||n>m) return 0;
    // cout<<"A"<<m<<" "<<n<<" "<<mul(fac[m],invfac[m-n])<<endl;
    return mul(fac[m],invfac[m-n]);
}
int f[N][N][N];
int n,m;
bool can[N];
int t[N];
int s[N];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    // cout<<"in"<<endl;
    init();
    // cout<<"out"<<endl;
    read(n);read(m);
    // cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++) 
    {
        char ch;
        cin>>ch;
        can[i]=ch-'0';
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        read(x);
        t[x]++;
    }
    f[0][0][0]=1;
    s[0]=t[0];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+t[i];
    for(int i=0;i<n;i++)
    {
        for(int a=0;a<=n;a++)
            for(int b=0;b<=n;b++)
            {
                // >i-a
                // if(f[i][a][b]) cout<<i<<" "<<a<<" "<<b<<" "<<f[i][a][b]<<endl;
                if(!f[i][a][b]) continue;
                if(can[i+1])
                    f[i+1][a+1][b+1]=pls(f[i+1][a+1][b+1],f[i][a][b]);
                else 
                {
                    int nwi=i+1,nwa=a,nwb=b+1;
                    int nwc=i-a+1;
                    for(int k=0;k<=t[nwc]&&k<=nwb;k++) f[i+1][a][nwb-k]=pls(f[i+1][a][nwb-k],mul(f[i][a][b],mul(A(t[nwc],k),C(nwb,k))));
                }
                // <=i-a
                int nwi=i+1,nwa=a,nwb=b;
                int nwlft=s[i-a]-(i-b);
                int nwc=i-a+1;
                int nwval=mul(f[i][a][b],nwlft);
                for(int k=0;k<=t[nwc]&&k<=nwb;k++) f[i+1][a][nwb-k]=pls(f[i+1][a][nwb-k],mul(nwval,mul(C(nwb,k),A(t[nwc],k))));
            }
    }
    int ans=0;
    for(int a=m;a<=n;a++)
        for(int b=0;b<=n;b++)
        {
            // if(f[n][a][b]) cout<<n<<" "<<a<<" "<<b<<" "<<f[n][a][b]<<endl;
            int nwc=n-a+1;
            int lft=s[n]-s[nwc-1];
            if(lft==b)
            {
                int val=f[n][a][b];
                // if(f[n][a][b]) cout<<"ans"<<n<<" "<<a<<" "<<b<<endl;
                val=mul(val,fac[b]);
                ans=pls(ans,val);
            }
        }
    writeln(ans);
    return 0;
}
// g++ cur.cpp -o cur -std=c++14 -O2 -static -Wall -Wextra 