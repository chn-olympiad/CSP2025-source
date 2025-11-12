#include<iostream>
#include<cstdio>
using namespace std;
/*
m条道路都被破坏了
修复第 i (1 ≤ i ≤ m) 条道路
的费用为 w i

还有 k 个准备进行城市化改造的乡镇
第 j (1 ≤ j ≤ k)
个乡镇对其进行城市化改造的费用为 c j

在城市化改造完第 j (1 ≤ j ≤ k) 个乡镇
后,可以在这个乡镇与原来的 n 座城市间建造若干条道路

在它与第 i (1 ≤ i ≤ n)
座城市间建造一条道路的费用为 a j,i

希望以最低的费用将原有的n座城市两两连通,也即任意两座原有的城市都能通过若干条修复或新建造的道路相互到达

求将原有的 n 座城市两两连通的最小费用

特殊性质 A:对于所有 1 ≤ j ≤ k,均有 c j = 0 且均存在 1 ≤ i ≤ n 满足 a j,i = 0。
*/
int n,m,k;
long long ans=-1;
int g[10005][10005];
bool vis[10005][10005];
void dfs(int t,int o,int z,long long sum){
    if(o==n&&z==m){
        ans=max(ans,sum);
        return ;
    }
    if(sum<=ans) return ;
    for(int i=1;i<=n;i++){
        if(vis[t][i]==0){
                vis[t][i]=1;
                if(vis[i][t]){
                   dfs(i,o,z,sum);
                }else{
                    dfs(i,o+1,z+1,sum+g[t][i]);
                }
        vis[t][i]=0;
        }
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        cin>>g[u][v];
        g[v][u]=g[u][v];
    }
    int c;
    for(int i=1,l;i<=k;i++){
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>l;
        }
    }
    dfs(1,1,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
return 0;
}
