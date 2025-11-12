#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e6;
int vis[MAX] = {};
struct fre{
    int u;
    int v;
    int w;
}a[MAX];
bool cmp(fre x,fre y) {
    return x.w < y.w;
}
int sss[MAX] = {};

int main()
{
    int n,m,k,cnt = 0,ans = 0;
    cin>>n>>m>>k;
    for(int i = 1;i <= m;i++) {
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    int tnt = 0;
    sort(a+1,a+m+tnt+1,cmp);
    for(int i = 1;i;i++) {
        if(!vis[a[i].u] || !vis[a[i].v]) {
            cnt++;
            ans += a[i].w;
            vis[a[i].v] = 1;
        }
        if(cnt == n-1) break;
    }
    cout<<ans;
    return 0;
}
