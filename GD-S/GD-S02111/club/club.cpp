#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL MAXN=1e5+5;
template<typename T>inline void read(T &x){
    bool f=1;x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=!f;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=(f?x:-x);return ;
}
template<typename T>inline void write(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');return ;
}
LL T,n,a[MAXN][5],chs[MAXN],b[MAXN],cnt;
bool cmp(LL x,LL y){
    return x>y;
}
void solve(){
    read(n);
    LL ans=0,sum[5]={0};
    for(LL i=1;i<=n;i++){
        read(a[i][1]);read(a[i][2]);read(a[i][3]);
        chs[i]=1;
        for(LL j=1;j<=3;j++){
            if(a[i][j]>a[i][chs[i]]){
                chs[i]=j;
            }
        }
        ans+=a[i][chs[i]];
        sum[chs[i]]++;
    }
    if(sum[1]<=n/2&&sum[2]<=n/2&&sum[3]<=n/2){
        write(ans);
        printf("\n");
        return ;
    }
    LL k=0;
    if(sum[1]>n/2)k=1;
    if(sum[2]>n/2)k=2;
    if(sum[3]>n/2)k=3;
    cnt=0;
    for(LL i=1;i<=n;i++){
        if(chs[i]!=k)continue;
        if(k==1){
            b[++cnt]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
        }
        if(k==2){
            b[++cnt]=max(a[i][1]-a[i][2],a[i][3]-a[i][2]);
        }
        if(k==3){
            b[++cnt]=max(a[i][2]-a[i][3],a[i][1]-a[i][3]);
        }
    }
    sort(b+1,b+cnt+1,cmp);
    for(LL i=1;i<=sum[k]-(n/2);i++){
        ans+=b[i];
    }
    write(ans);
    printf("\n");
}
int main(){
    // LL tim=clock();
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    read(T);
    while(T--){
        solve();
    }
    // cerr<<clock()-tim<<endl;
}