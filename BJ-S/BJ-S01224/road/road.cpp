#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[20005],cnt,c[15];
int find(int x){
    if(f[x] == x){
        return x;
    }
    return f[x] = find(f[x]);
}
long long ans,ans2,ans3;
struct bian{
    int u,v,w;
    bool operator <(const bian _)const{
        return w < _.w;
    }
}b[1000005],b3[15][10005];
int flag[15];
void check(){
    ans3 = ans2;
    for(int i = 1;i <= n + k;i++){
        f[i] = i;
    }
    priority_queue<pair<int,pair<int,int> > > q;
    int cntt = n;
    q.push({-b3[0][1].w,{0,1}});
    for(int i = 1;i <= k;i++){
        if(flag[i]){
            cntt++;
            q.push({-b3[i][1].w,{i,1}});
        }
    }
    while(cntt > 1){
        if(q.empty()){
            break;
        }
        pair<int,int> now = q.top().second;
        q.pop();
        int u = b3[now.first][now.second].u;
        int v = b3[now.first][now.second].v;
        int w = b3[now.first][now.second].w;
        if(find(u) != find(v)){
            f[f[u]] = f[v];
            ans3 += w;
            cntt--;
            if(ans3 > ans){
                break;
            }
        }
        if(now.second < n - 1 || (now.second == n - 1 && now.first > 0)){
            q.push({-b3[now.first][now.second + 1].w,{now.first,now.second + 1}});
        }
    }
    ans = min(ans,ans3);
    //cerr << ans << " ";
}
void dfs(int x){
    if(x > k){
        //cerr << 2;
        check();
        //cerr << 2;
        return;
    }
    dfs(x + 1);
    ans2 += c[x];
    flag[x] = 1;
    dfs(x + 1);
    flag[x] = 0;
    ans2 -= c[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cin >> b[i].u >> b[i].v >> b[i].w;
    }
    sort(b + 1,b + m + 1);
    for(int i = 1;i <= n;i++){
        f[i] = i;
    }
    for(int i = 1;i <= m;i++){
        if(find(b[i].u) != find(b[i].v)){
            f[f[b[i].u]] = f[b[i].v];
            ans += b[i].w;
            cnt++;
            b3[0][cnt] = b[i];
        }
        if(cnt == n - 1){
            break;
        }
    }
    //cerr << b3[0][cnt].w << " " << cnt << " " << n << '\n';
    for(int i = 1;i <= k;i++){
        cin >> c[i];
        for(int j = 1;j <= n;j++){
            int w;
            cin >> w;
            b3[i][j] = bian{n + i,j,w};
        }
        sort(b3[i] + 1,b3[i] + n + 1);
    }
    //cerr << 1;
    dfs(1);
    cout << ans << '\n';
    return 0;
}
