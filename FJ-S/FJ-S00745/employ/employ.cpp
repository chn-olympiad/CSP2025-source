#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define forto(i,a,b) for(int i(a),_##i(b);i<=_##i;i++)
#define forbk(i,a,b) for(int i(a),_##i(b);i>=_##i;i--)
#define forv(i,a) for(int i(0),_##i(a);i<_##i;i++)
#define il inline
#define mkp make_pair
#define eb emplace_back
using namespace std;
il int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N=505,P=998244353;
int n,m,a[N],c[N];
char s1[N];
// int f[2][N][N][N],nw=1,pr=0,sum[N];
// 当前值为 i，有 j 个人被录取，第 i 个未被录取的位置在 k，前缀已经放了 l 个未被录取的人
/*
f[j][k][l] -> f[j+1][k][l]*(k-i-j)
f[j][k][l] -> f[j][k][l]*(n-k)
f[j][k][l] -> f[j][k][l+1]
*/

il void addto(int &x,int y){
    x+=y;if(x>=P)x-=P;
}
int f[2][20][300005],nw=1,pr=0;//,pos[N],tot=0;

namespace SP1{
    il void sol(){
        int ans=1;
        forto(i,1,n)ans=1ll*ans*i%P;
        forto(i,1,n)if(s1[i]=='0'||a[i]==0){ans=0;break;}
        printf("%d\n",ans),exit(0);
    }
};
// namespace SP2{
//     il void sol(){

//     }
// };

signed main(){
    freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
    n=read(),m=read(),scanf("%s",s1+1);
    // int c0=0;
    // forto(i,1,n)sum[i]=sum[i-1]+(s[i]=='1'),c0+=(s[i]=='0');
    forto(i,1,n)a[i]=read(),c[a[i]]++;

    if(m==n)SP1::sol();

    // forto(i,1,n)if(s[i]=='1')pos[tot++]=i;
    // int pr=0,nw=1;
    f[0][0][0]=1;
    forto(i,1,n){
        forv(s,1<<n)if(__builtin_popcount(s)==i-1){
            forto(j,1,n){
                if(s>>(j-1)&1)continue;
                forto(c,0,m){
                    bool fg=(s1[i]=='0'||c>=a[j]);
                    addto(f[nw][c+fg][s|(1<<(j-1))],f[pr][c][s]);
                }
            }
        }
        swap(nw,pr),memset(f[nw],0,sizeof(f[nw]));
    }
    int ans=0;
    forto(j,m,n)addto(ans,f[pr][n-j][(1<<n)-1]);
    printf("%d\n",ans);
    // forto(i,0,n)f[0][0][i][0]=1;
    // int cnt=0,c1=0;
    // forbk(i,n,0){
    //     forto(t,1,c[i]){
    //         forto(j,0,n)forto(k,0,n)forto(l,0,n)if(f[pr][j][k][l]){
    //             cerr<<i<<' '<<j<<' '<<k<<' '<<l<<'\n';
    //             if(k>=i+j)addto(f[nw][j+1][k][l],1ll*f[pr][j][k][l]*(k-i-j)%P);
    //             addto(f[nw][j][k][l],1ll*f[pr][j][k][l]*(n-k)%P);
    //             addto(f[nw][j][k][l+1],f[pr][j][k][l]);
    //             // int l=cnt-j-i;
    //             // addto(f[nw][j+1][k][r],1ll*f[pr][j][k][r]*(c1-j)%P);// 被录取
    //             // addto(f[nw][j][k][r-1],1ll*f[pr][j][k][r]*r%P);// 不被录取且被排到前面的 0 处
    //             // addto(f[nw][j][k][r],f[pr][j][k][r]);// 不被录取且被排到后面
    //         }
    //         upd();
    //     }
    //     if(i){
    //         forto(j,0,n)forto(k,0,n)forto(l,0,n)if(f[pr][j][k][l]){
    //             cerr<<i<<' '<<j<<' '<<k<<' '<<l<<'\n';
    //             if(k==n){
    //                 forbk(k1,k,0){
    //                     addto(f[nw][j][k1][l],f[pr][j][k][l]);
    //                     if(s[k1]=='0')break;
    //                 }
    //             }
    //             forbk(k1,k-1,0){
    //                 if(l)addto(f[nw][j][k1][l-1],1ll*f[pr][j][k][l]*l%P);
    //                 if(s[k1]=='0')break;
    //             }
    //         }
    //         upd();
    //     }
    // }
    // int ans=0;
    // forto(j,m,n)addto(ans,f[pr][j][0][0]);
    // printf("%d\n",ans);
    return 0;
}