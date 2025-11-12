#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=998244353LL;
/*
dp[i][j]:i:max=j fangan
f[i][j]:i:sum=j fangan
sum<=10000!!!!!!!!!!
a NGGYU problem.
This is not a NGGYU problem, This is a THINKFUL problem!!!!!!!!!!--candybar
Problem above *2000 is not NGGYU!!!!!!!!!!--candybar
(But this problem is below *2000, isn't it?)
No No No, I'm NGGYUed.
My solution is false.
..........
No No No, My solution is true!
But how to calculate dp?
Oh, I know that!!!!!!!!!!
sort arr!!!!!!!!!!
dp[j]:max=arr[j] answer (j must be selected)
f[i][j][0/1]:i:sum=j fangan (i must/must not be selected)
g[i][j][0/1]:i:sum<=j fangan (pre sum f) (i must/must not be selected)
h[i][j]:sum>j fangan=qpow(2,i-1)-g[i][j][1]; (i must be selected)
%%%CCF PLEASE LET ME AC!!!!!!!!!!
candybar tql
lzq tql
%%%%%%%%%%
DO NOT PLAY TETRIS IN GNU EMACS!!!!!!!!!!(bushi
AC T4? Can I??????????
RP++
sto %%% candybar %%% orz
sto %%% lzq %%% orz
I want to be on mihuoxingweidashang
Please follow me on luogu. Thanks.
Oops, I'm not kkksc03.
What is my UID??????????
*/
int arr[5005],n,f[2][10005][2],g[2][10005][2],ans=0;
bool pos=0;
LL qpow(LL a,LL b){
    LL ans=1LL;a%=mod;
    while (b){
        if (b&1){(ans*=a)%=mod;}
        (a*=a)%=mod;
        b>>=1;
    }
    return ans;
}
LL madd(LL a,LL b){return (a+b)%mod;}
LL msub(LL a,LL b){return (a+mod-b)%mod;}
LL mmul(LL a,LL b){return (a*b)%mod;}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){scanf("%d",arr+i);}
    sort(arr+1,arr+1+n);
    f[0][0][0]=1;for (int i=0;i<=10000;++i){g[0][i][0]=1;}
    for (int i=1;i<=n;++i){
        pos=(!pos);memset(f[pos],0,sizeof f[pos]);memset(g[pos],0,sizeof g[pos]);
        for (int j=0;j<=10000;++j){
            if (j>=arr[i]){f[pos][j][1]=madd(f[pos][j][1],madd(f[!pos][j-arr[i]][0],f[!pos][j-arr[i]][1]));}
            f[pos][j][0]=madd(f[pos][j][0],madd(f[!pos][j][0],f[!pos][j][1]));
        }
        g[pos][0][0]=f[pos][0][0];g[pos][0][1]=f[pos][0][1];
        for (int j=1;j<=10000;++j){
            g[pos][j][0]=madd(g[pos][j-1][0],f[pos][j][0]);
            g[pos][j][1]=madd(g[pos][j-1][1],f[pos][j][1]);
        }
        ans=madd(ans,msub(qpow(2,i-1),g[pos][arr[i]<<1][1]));
    }
    printf("%d\n",ans);
    return 0;
}
