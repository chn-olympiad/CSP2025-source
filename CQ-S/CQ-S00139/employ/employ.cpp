#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define f(i,j,n) for(int i=j;i<=n;i++)
#define F(i,n,j) for(int i=n;i>=j;i--)
#define updmin(a,b) a=min(a,b)
#define updmax(a,b) a=max(a,b)
#define updsum(a,b) a=(a+(b))%mod
#define updtim(a,b) a=a*(b)%mod
using namespace std;
typedef pair<int,int> pii;
namespace fsd{
    const int MX=1<<20;
    char buf[MX],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MX,stdin),p1==p2)?EOF:*p1++)
    inline int read(){
        int ak=0,csp=1;
        char c=gc();
        while(!isdigit(c)){if(c=='-')csp=-1;c=gc();}
        while(isdigit(c))ak=ak*10+c-'0',c=gc();
        return ak*csp;
    }
    inline char readc(){
        char c=gc();
        while(c!='0'&&c!='1')c=gc();
        return c;
    }
}
using namespace fsd;
const int N=510;
const int mod=998244353;
int C[N][N];
int n,m;
bool t[N];
int a[N];
int dp[2][N];
int c[N],sum[N],tim[N],rs[N];
void gs(){
    n=read(),m=read();
    tim[0]=1;
    f(i,1,n)tim[i]=tim[i-1]*i%mod;
    f(i,0,n){
        C[i][0]=C[i][i]=1;
        f(j,1,i-1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    int ss=0;
    f(i,1,n){
//        cout<<ss<<endl;
        int c=readc()-'0';
        t[i]=c;
        rs[i]=rs[i-1]+(!t[i]);
    }
    f(i,1,n){
        a[i]=read();
        c[a[i]]++;
    }
    sum[0]=c[0];
    f(i,1,n)sum[i]=sum[i-1]+c[i];
    dp[0][0]=1;
    f(i,1,n){
        f(j,0,i)dp[i&1][j]=0;
        f(j,0,i-1){
            //<j j-rs[i-1] >=j i-1-j
            if(t[i]){
				updsum(dp[i&1][j],dp[i&1^1][j]);
	            f(ls,0,min(c[j],i-1-j)){
	                int r=C[i-1-j][ls]*C[c[j]][ls]%mod*tim[ls]%mod;
//	                cout<<j<<"("<<dp[i&1^1][j]<<")->"<<j+1<<" "<<ls<<" "<<r<<" "<<sum[j]<<endl;
	                updsum(dp[i&1][j+1],dp[i&1^1][j]*r%mod*(sum[j]-ls-(j-rs[i-1])));
	            }
			}else{
				updsum(dp[i&1][j+1],dp[i&1^1][j]);
			}
        }
//        f(j,0,i)cout<<dp[i&1][j]<<" ";cout<<endl;
    }
    int ans=0;
    f(j,0,n-m)updsum(ans,dp[n&1][j]*tim[n-j+rs[n]]);
    printf("%lld\n",ans);
}
//#define DXN
signed main(){
//     freopen("employ1.in","r",stdin);
#ifndef DXN
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
#endif
#ifdef NXD
    int t=read();while(t--)
#endif
    gs();
    return 0;
}
