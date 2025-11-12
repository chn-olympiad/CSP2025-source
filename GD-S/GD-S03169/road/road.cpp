#include<bits/stdc++.h>
using namespace std;
const int MAXM =  1e6 + 5,MAXN = 1e4 + 5, MAXK = 11;
int n,m,k;//n, m, k，分别表示原有的城市数量、道路数量和准备进行城市化改造的乡镇数量。
int u[MAXM],v[MAXM],w[MAXM];//ui, vi, wi，表示第 i 条道路连接的两座城市与修复该道路的费用。
int c[MAXK];//城镇化的费用
int a[MAXK][MAXN];//建造一条道路的费用为a j,i

int parent[MAXN+MAXK];
int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}
void unite(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy) parent[fx] = fy;
}
bool connected(int x,int y){
    return find(x)==find(y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(int i=0;i<MAXN;i++)
        parent[i] = i;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
        cin >> u[i] >> v[i] >> w[i];
    for(int j=1;j<=k;j++){
        cin >> c[j];
        for(int i=1;i<=n;i++){
             cin >> a[j][i];
             if(a[j][i]==0)
                unite(MAXN+j,i);
        }
    }

    long long ans = 0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++)
            if(connected(i+MAXN,j)){
                for(int t=1;t<=n;t++)
                    if(t!=j&&!connected(t,j)){
                        unite(t,j);
                        ans += min(a[i][t],(int)1e9);
                    }
            }
    }
    cout << ans;
    return 0;
}