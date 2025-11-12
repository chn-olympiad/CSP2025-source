#include <bits/stdc++.h>
#define il inline
using namespace std;
typedef long long ll;
il int read(){
    int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int N=5e5+5;
int T,n,a[N][4],b[N],c[N],in[4];
int x,y,z,u,v,w;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);for(int i=0;i<=3;++i) in[i]=0;
        for(int i=1;i<=n;++i){
            x=-1,y=0;
            for(int j=1;j<=3;++j) a[i][j]=read(),x=max(x,a[i][j]);
            for(int j=1;j<=3;++j) if(a[i][j]==x){y=j;break;}
            ++in[y],b[i]=y;
        }
        x=0;for(int i=1;i<=3;++i) x=max(x,in[i]);
        if(x<=n/2){
            x=0;for(int i=1;i<=n;++i) x+=a[i][b[i]];
            printf("%d\n",x);continue;
        }
        int ans=0;
        for(int j=1;j<=3;++j){
            int cur=0;
            for(int i=1;i<=n;++i){
                x=a[i][j],y=-1;for(int k=1;k<=3;++k) if(j!=k) y=max(y,a[i][k]);
                c[i]=y-x,cur+=x;
            }
            sort(c+1,c+1+n);
            for(int i=n/2+1;i<=n;++i) cur+=c[i];
            ans=max(ans,cur);
        }
        printf("%d\n",ans);
    }

    return 0;
}
