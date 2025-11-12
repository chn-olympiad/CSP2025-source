#include<bits/stdc++.h>
using namespace std;
const int M=10010;
int n,m,k,ans=0;
int a[M],c[M][4],d[15][M],f[M][2];
vector<int> v[M];
bool bfs(int x,int y){
queue<int> q;
q.push(x);
    while(!q.empty()){
        if(q.front()==y) return true;
        for(int i=0;i<f[q.front()][0];i++)
            if(f[q.front()][1]==0){
            q.push(v[q.front()][i]);
            f[q.front()][1]=1;}
    q.pop();

    }
return false;
}
void plant(int x,int y){
f[x][0]++,f[y][0]++;
v[x].push_back(y);
v[y].push_back(x);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
        for(int i=1;i<=m;i++){
        cin>>c[i][1]>>c[i][2]>>c[i][3];
        }
        for(int i=1;i<=k;i++){
        cin>>d[i][0];
            for(int j=1;j<=n;j++)
            cin>>d[i][1];
        }
        for(int i=1;i<=m;i++)
            for(int j=i+1;j<=m;j++)
                if(c[i][3]>c[j][3])
                swap(c[i],c[j]);
        for(int i=1;i<=m;i++){
        bool flag=true;
            if(bfs(c[i][1],c[i][2])) continue;
            if(d[i][0]<c[i][3]&&d[i][n+1]==0)
                for(int j=1;j<=k&&flag;j++)
                    if(d[j][c[i][2]]+d[i][0]<c[i][3])
                    {d[j][n+1]=1,ans+=d[j][c[i][2]]+d[j][0];
                     plant(c[i][1],c[i][2]);flag=false;}
            if(flag) {ans+=c[i][3];plant(c[i][1],c[i][2]);}
        }
    cout<<ans;
    return 0;
}