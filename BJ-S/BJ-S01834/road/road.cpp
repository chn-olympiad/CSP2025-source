#include<bits/stdc++.h>
using namespace std;

int a[1010][1010];
int c[1010],r[1010][1010];
bool built[1010],vis[1010];
int n,m,k,minnn;
void dfs(int pos,int cnt,int ans){
    if(cnt == n){
        minnn = min(ans,minnn);
        return;
    }
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            vis[i] = 1;
            for(int j = 0; j < k; j++){
                if(!built[j]){
                    if(a[pos][i] > c[j]+r[j][i]+r[j][pos]){
                        ans += c[j]+r[j][i]+r[j][pos];
                        built[j] = 1;
                    }
                    else{
                        ans += a[pos][i];
                    }
                }
                else{
                    if(a[pos][i] > r[j][i]+r[j][pos]){
                        ans += r[j][i]+r[j][pos];
                    }
                    else{
                        ans += a[pos][i];
                    }
                }
            }
            dfs(i,cnt+1,ans);
            vis[i] = 0;
        }
    }

    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            a[i][j] = 0x3f3f3f3f;
        }
    }
    cin>>n>>m>>k;
    for(int i = 0; i < m; i++){
        int x,y,w;
        cin>>x>>y>>w;
        a[x][y] = w;
        a[y][x] = w;
    }
    for(int i = 0; i < k; i++){
        int a;
        cin>>a;
        c[i] = a;
        for(int j = 0; j < n; j++){
            int w;
            cin>>w;
            r[a][j] = w;
        }
    }
    dfs(0,1,0);
    cout<<minnn<<endl;

    return 0;
}
