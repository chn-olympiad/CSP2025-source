#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int matrix[maxn][maxn];
int lists[maxn];
int n,m,k;
long long miner=1000000000000;
int dfs(int pos,int num,long long cos) {
    lists[pos]=1;
    if (num==n) {
        miner=min(miner,cos);
    }
    else {
        for (int i=1;i<=n+1;i++) {
            if (matrix[i][pos]!=-1 and !lists[i] and i!=pos) {
                lists[i]=1;
                dfs(i,num+1,cos+matrix[i][pos]);
                lists[i]=0;
            }
        }
    }
}
int main() {
    int pos1,pos2,cost;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0;i<=n+1;i++) {
        for (int j=0;j<=n+1;j++) matrix[i][j]=-1;
    }
    for (int i=0;i<m;i++) {
        scanf("%d %d %d",&pos1,&pos2,&cost);
        matrix[pos1][pos2]=cost;
        matrix[pos2][pos1]=cost;
    }
    dfs(1,1,0);
    cout<<miner;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
