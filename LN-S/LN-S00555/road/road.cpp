#include <bits/stdc++.h>

using namespace std;
#define int long long
const int DIAN = 1e4+15,BIAN=1e6+15;
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<3)+(x<<1)+ch-'0';
        ch = getchar();
    }
    return x*f;
}
int n,m,k,c[15],dis[DIAN], vis[DIAN];
bool ip[15];
int g[DIAN][DIAN];
void Prime(){
    memset(dis, 0x3f3f, sizeof(dis));
    dis[1]=0;
    //for(int i = 1;i <= k; i++)dis[i+n]=c[i];
    for(int i = 1; i < n; i++){
        int x = 0;
        for(int j = 1; j <= n+k; j++)
            if(!vis[j] && (x==0||dis[j]<dis[x]))x=j;
        vis[x]=1;
        for(int y = 1; y <= n+k; y++){
            /*
            if(y<=n){
                /*if(x <= n){if(!vis[y])dis[y] = min(dis[y], g[x][y]);}
                //else{if(!vis[y])dis[y] = min(dis[y], c[x-n]+g[x][y]);}
            }
            else {if(!vis[y])dis[y] = min(dis[y], c[y-n]+g[x][y]);}
        */
            if(!vis[y]){
                //if(x <= n){
                    if(y <= n)dis[y] = min(dis[y], g[x][y]);
                    else{
                        if(dis[y]>c[y-n]+ g[x][y]){
                            dis[y] = c[y-n]+g[x][y];

                        }
                    }
                //}
                //else{
                //    dis[y] = min(dis[y], c[x-n]+g[x][y]);
                //}
            }

        }
        /*
        for(int i = 1; i <= n+k; i++)cout << dis[i] << " ";
        cout << endl;*/
    }
}
struct cun{
    int ci,lu[DIAN];
}p[15];
bool cmp(cun a, cun b){
    return a.ci < b.ci;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    n = read(), m = read(), k = read();
    memset(g,0x3f3f,sizeof(g));
    for(int i = 1; i <= m; i++){
        int u,v,c;
        u=read(), v=read(), c=read();
        g[u][v] = g[v][u] = min(g[u][v], c);
    }
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)cout << g[i][j] << " ";
        cout << endl;
    }*/
    //sort???
    for(int i = 1; i <= k; i++){
        p[i].ci=read();
        for(int j = 1; j <= n; j++){
            int cos = read();
            p[i].lu[j]=cos;
        }
    }
    sort(p+1,p+k+1,cmp);
    for(int i = 1; i <= k; i++){
        c[i] = p[i].ci;
        for(int j = 1; j <= n; j++){
            g[i+n][j] = g[j][i+n] = p[i].lu[j];
        }
    }
    Prime();
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dis[i];
    }
    printf("%lld",ans);
    return 0;
}
