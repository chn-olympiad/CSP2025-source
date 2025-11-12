#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int u,v,w;
}a[1500005],h[1500005];
int b[15][10005],n,m,k,ans,ln,fa[10015];
bool cmp(node a,node b){
    return a.w<b.w;
}
int find(int now){
    return (fa[now] == now?now:fa[now] = find(fa[now]));
}
int work(){
    for(int i = 1;i<=m;i++){
        a[i] = h[i];
    }
    sort(a+1,a+m+1,cmp);
    for(int i = 1;i<=n;i++){
        fa[i] = i;
    }
    int num,sum;
    num = n;
    sum = 0;
    for(int i = 1;num>1;i++){
        int fu,fv;
        fu = find(a[i].u);
        fv = find(a[i].v);
        if(fu == fv){
            continue;
        }
        num--;
        sum = sum+a[i].w;
        fa[fu] = fv;
    }
    return sum;
}
void dfs(int now,int sum){
    if(sum>ans){
        return;
    }
    if(now>k){
        ans = min(ans,sum+work());
        return;
    }
    int nowm;
    nowm = m;
    n++;
    for(int i = 1;i<=ln;i++){
        h[++m] = {n,i,b[now][i]};
    }
    dfs(now+1,sum+b[now][0]);
    m = nowm;
    n--;
    dfs(now+1,sum);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    ln = n;
    for(int i = 1;i<=m;i++){
        cin>>h[i].u>>h[i].v>>h[i].w;
    }
    for(int i = 1;i<=k;i++){
        for(int j = 0;j<=n;j++){
            cin>>b[i][j];
        }
    }
    ans = 1e18;
    dfs(1,0);
    cout<<ans<<"\n";
    return 0;
}
