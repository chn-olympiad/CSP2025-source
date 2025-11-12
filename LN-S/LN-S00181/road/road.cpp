#include<bits/stdc++.h>
using namespace std;

const int N=1e6+9;
int n,m,k;
int u,v,c;
bool cka=true;
vector<vector<int>> edge,cost;
vector<vector<bool>>visedge;
vector<int> chudu;
int ccost[N],indx[N],ll[N],rr[N];
int costj[10+9];
vector<bool> vis;

//int f[1e6+9];

int sumcost1;

void check1(int x){
    /*if(vis[x]){
        return;
    }
    vis[x]=true;*/

    if(x>n+k){
        return;
    }

    int siz=edge[x].size();
    for(int i=0;i<siz;i++){
        int vv=edge[x][i];
        if(chudu[x]>1&&chudu[vv]>1&&(!visedge[x][vv])){
            chudu[x]--;
            chudu[vv]--;
            visedge[x][vv]=true;
            visedge[vv][x]=true;
            sumcost1 -= cost[x][i];
        }
    }
    check1(++x);
    return;
}

bool cmp(int a,int b){
    ccost[a]>ccost[b];
}


int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    scanf("%d%d%d",&n,&m,&k);
    edge.resize(n+k+1);
    cost.resize(n+k+1);
    chudu.resize(n+k+1);
    vis.resize(n+k+1);
    visedge.resize(n+k+1);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&u,&v,&c);
        edge[u].push_back(v);
        edge[v].push_back(u);
        ccost[i]=c;
        indx[i]=i;
        ll[i]=u;
        rr[i]=v;
        cost[u].push_back(c);
        cost[v].push_back(c);
        chudu[u]++;
        chudu[v]++;
        sumcost1 += c;
    }
    for(int j=1;j<=k;j++){
        scanf("%d",&costj[j]);
        if(costj[j]){
            cka=false;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&c);
            if(c){
                cka=false;
            }
            edge[n+i+1].push_back(i);
            edge[i].push_back(n+i+1);
            cost[n+i+1].push_back(c);
            cost[i].push_back(c);
            sumcost1 += c;
        }
    }

    //sort(indx+1,indx+n+1,cmp);

    /*for(int i=1;i<=n;i++){
        printf("%d ",ccost[i]);
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        printf("%d ",indx[i]);
    }*/

    check1(1);

    printf("%d",sumcost1);

    return 0;
}

/*4 4 0
1 2 2
1 3 5
1 3 1
2 3 3*/
