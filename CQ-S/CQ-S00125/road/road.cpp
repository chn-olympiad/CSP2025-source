#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e4+5,M=2e6+5,K=15;
int n,m,k,s[K][N],fa[1030][N];bool f[N];LL ans[1030];
struct node{
    int x,y,z,tp;
    friend bool operator<(node a,node b){return a.z<b.z;}
}e[M];
int find(int x,int tp){return x==fa[tp][x]?x:fa[tp][x]=find(fa[tp][x],tp);}
int read(int ans=0){
    char x;bool f=0;
    x=getchar();
    while(x>'9'||x<'0') x=='-'?f=1:0,x=getchar();
    while(x<='9'&&x>='0') ans=ans*10+x-'0',x=getchar();
    return ans*(f?-1:1);
}
int main(){//72pts(?)
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    // double t1=time(0);
    n=read(),m=read(),k=read();
    if((m+n*k)*(1<<k)<=1e8){
        for(int i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].z=read(),e[i].tp=0;
        for(int i=1;i<=k;i++){
            for(int j=0;j<=n;j++)
                s[i][j]=read(),j>0?(e[++m].x=j,e[m].y=n+i,e[m].z=s[i][j],e[m].tp=i):0;
        }
        for(int i=0;i<=(1<<k)-1;i++){
            iota(fa[i]+1,fa[i]+1+n+k,1);
            for(int j=1;j<=k;j++) if((i>>j-1)&1) ans[i]+=s[j][0];
        }
        sort(e+1,e+1+m);
        for(int x,y,z,tp,i=1;i<=m;i++){
            tp=e[i].tp,x=e[i].x,y=e[i].y,z=e[i].z;
            for(int j=0,x_,y_;j<=(1<<k)-1;j++)
                if((tp==0||(j>>tp-1)&1)&&(x_=find(x,j))!=(y_=find(y,j))) fa[j][y_]=x_,ans[j]+=z;
        }
        LL ANS=2e18;
        for(int i=0;i<=(1<<k)-1;i++){
            bool f=1;
            for(int j=1;j<n;j++)
                if(find(j,i)!=find(j+1,i)) {f=0;break;}
            f?ANS=min(ANS,ans[i]):0;
        }
        printf("%lld",ANS);
    }else{
        iota(fa[0]+1,fa[0]+1+n+k,1);
        for(int i=1;i<=m;i++) e[i].x=read(),e[i].y=read(),e[i].z=read();
        for(int i=1;i<=k;i++)
            for(int j=0;j<=n;j++)
                s[i][j]=read(),j>0?(e[++m].x=j,e[m].y=n+i,e[m].z=s[i][j]):0;
        sort(e+1,e+1+m);
        for(int x,y,z,i=1;i<=m;i++){
            x=find(e[i].x,0),y=find(e[i].y,0),z=e[i].z;
            if(x!=y) fa[0][y]=x,ans[0]+=z;
        }
        printf("%lld",ans[0]);
    }
    // printf("\n%.5lf",time(0)-t1);
    return 0;
}