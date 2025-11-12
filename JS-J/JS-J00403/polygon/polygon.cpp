#include<bits/stdc++.h>
#define N 5010
#define int long long
using namespace std;
int n,ans,cnt,m1,a[N];
bool vis[N];
inline int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') y=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*y;
}
inline void write(int x){
    if(!x) putchar('0');
    char F[200];
    if(x<0) putchar('-'),x=-x;
    int tmp=x,cnt=0;
    while(tmp>0){
        F[++cnt]=tmp%10+'0';
        tmp/=10;
    }
    while(cnt>0) putchar(F[cnt]),cnt--;
}
bool check(int x,int y){
    if(2*x<y) return 1;
    return 0;
}
void dfs(int x,int y,int maxn,int sum){
    if(n-x+1<3-y) return;
    if(x>n){
        if(y>=3&&check(maxn,sum)) ans=(ans+1)%998244353;
        return;
    }
    dfs(x+1,y,maxn,sum);
    vis[x]=1;
    dfs(x+1,y+1,max(maxn,a[x]),sum+a[x]);
    vis[x]=0;
}
int get(int x){
    int t=1;
    if(x==0) return 1;
    for(int j=1;j<=x;j++) t=(t*j)%998244353;
    return t;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        m1=max(m1,a[i]);
    }
    if(m1==1){
        int m=get(n);
        for(int i=3;i<=n;i++){
            ans+=(m/get(i)/get(n-m))%998244353;
        }
        write(ans);
        return 0;
    }
    dfs(1,0,0,0);
    write(ans);
    return 0;
}
