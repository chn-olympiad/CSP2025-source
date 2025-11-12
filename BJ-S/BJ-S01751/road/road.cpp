#include <iostream>
#include <cstring>
using namespace std;

int n,m,k;
int c[19];
int cost[19][10090];

struct road{
    int s;
    int e;
    int w;
    int next;
}a[100090];
int head[10090]={},cnt=0;
int bg[10090]={};

void add_bian(int u,int v,int value){
    cnt++;
    a[cnt].s=u;
    a[cnt].e=v;
    a[cnt].w=value;
    a[cnt].next=head[u];
    head[u]=cnt;
    return;
}

bool go[1090]={},f=0;
int sent=1e9+90;
void bfs(int x,int en,int sum){
    sum+=bg[x];
    //cout << x << " " << sum << endl;
    if(en==x){
        sent=min(sent,sum);
        return;
    }
    for(int i = head[x];i;i=a[i].next){
        if(go[a[i].e]==0){
            go[a[i].e]=1;
            bfs(a[i].e,en,sum+a[i].w);
            go[a[i].e]=0;
        }
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        int u,v,value;
        cin >> u >> v >> value;
        add_bian(u,v,value);
        add_bian(v,u,value);
    }
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        bg[n+i]=c[i];
        for(int j = 1;j <= n;j++){
            cin >> cost[i][j];
            add_bian(n+i,j,cost[i][j]);
            add_bian(j,n+i,cost[i][j]);
        }
    }
    int maxn=-1;
    for(int i = 2;i <= n;i++){
        sent=1e9+90;
        f=0;
        bfs(1,i,0);
        cout << sent << endl;
        maxn=max(maxn,sent);
    }
    cout << maxn << endl;
    return 0;
}
