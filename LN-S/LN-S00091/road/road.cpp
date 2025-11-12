#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int minn=INT_MAX;
vector<int> p[1000010];
vector<int> q[1000010];
int c[20];
int f2[10010];
int a[20][10010];
struct node{
    int x;
    int step;
    int cnt;
}t[1000010];
int b[1000010][10];
int f[100][10010];
void bfs(int st){
    int head=1;
    int tail=1;
    t[tail].x=st;
    t[tail].step=0;
    t[tail].cnt=1;
    tail++;
    f[1][st]=1;
    while(head<tail){
        int x0=t[head].x;
        int step=t[head].step;
        int cnt=t[head].cnt;
        f[cnt+1][x0]=1;
        if(cnt==n){
            if(step<minn){
                minn=step;
            }
        }
        for(int i=0;i<p[x0].size();i++){
            int nx=p[x0][i];
            int step0=step+q[x0][i];
            if(f[cnt][nx]!=1 && step0<minn){
                t[tail].x=nx;
                t[tail].step=step0;

                t[tail].cnt=cnt+1;
                for(int i=1;i<=n;i++){
                    if(i==x0){
                        continue;
                    }
                    f[cnt][i]=f[cnt-1][i];
                }
                tail++;
            }
        }
        for(int i=1;i<=k;i++){
            if(c[i]>=minn){
                continue;
            }
            for(int j=1;j<=n;j++){
                int step0=step+a[i][x0]+a[i][j];
                if(b[head][i]==0){
                    step0+=c[i];
                }
                if(f[cnt-1][j]==1 || step0>=minn){
                    continue;
                }
                t[tail].x=j;
                t[tail].step=step0;
                t[tail].cnt=cnt+1;
                for(int i=1;i<=n;i++){
                    if(cnt==x0){
                        continue;
                    }
                    f[cnt][i]=f[cnt-1][i];
                }
                for(int g=1;g<=k;g++){
                    b[tail][g]=b[head][g];
                }
                b[tail][i]=1;
                tail++;
            }
        }
        head++;
    }
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        p[u].push_back(v);
        p[v].push_back(u);
        q[u].push_back(w);
        q[v].push_back(w);
    }
    for(int i=1;i<=k;i++){
        cin >> c[i];
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        memset(t,0,sizeof(t));
        memset(b,0,sizeof(b));
        bfs(i);
    }
    cout << minn;
    return 0;
}
