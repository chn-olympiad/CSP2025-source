#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,c[15],fa[10500],m,ans = 1e12,idx[15];
struct st{
    int u;
    int v;
    int w;
}e[1000050],a[15][1050];
bool cmp(st xx,st yy){
    return xx.w<yy.w;
}
int f(int xx){
    if(xx == fa[xx])return xx;
    return fa[xx] = f(fa[xx]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    int x,y,z;
    for(int i = 1;i<=m;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        e[i] = {x,y,z};
    }
    sort(e+1,e+1+m,cmp);
    for(int i = 1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j = 1;j<=n;j++){
            scanf("%lld",&z);
            a[i][j] = {n+i,j,z};
        }
        sort(a[i]+1,a[i]+n,cmp);
    }
    for(int i = 1;i<=(1<<k);i++){
        for(int j = 1;j<=k;j++)idx[j]=1;
        for(int j = 1;j<=n+k;j++)fa[j] = j;
        int res = 0,cnt = 0,cont = 0;
        int ttt = (1<<k)-1;
        for(int j = 1,t = 1;j<=min(i,ttt);j<<=1,t++){
            if(i&j){
                res+=c[t];
                cont++;
            }
        }
        int p = 1;
        while(cnt<n-1+cont){
            st noww = e[p];
            int pos = 0;
            if(p>m){
                noww.w = 1e9;
            }
            for(int j = 1,t = 1;j<=i;j<<=1,t++){
                if(i&j){
                    if(idx[t]>n)continue;
                    if(a[t][idx[t]].w<noww.w){
                        noww = a[t][idx[t]];
                        pos = t;
                    }
                }
            }
            if(pos == 0){
                p++;
            }
            else idx[pos]++;
            int fu = f(noww.u),fv = f(noww.v);
            if(fu!=fv){
                fa[fu] = fv;
                cnt++;
                res+=noww.w;
            //    cout<<pos<<" "<<noww.w<<" ";
            }
        }
     //   cout<<res<<endl;
        ans = min(ans,res);
    }
    printf("%lld",ans);
    return 0;
}
