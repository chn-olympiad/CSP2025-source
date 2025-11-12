#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,inf=(1<<30)-1;
int n,ans,a[N][5],dp[N/2];
void dfs(int p,int v1,int v2,int v3,int hp) {
    if (p==n+1) {
        ans=max(ans,hp);
        return;
    }
    if(v1+1<=n/2) dfs(p+1,v1+1,v2,v3,hp+a[p][1]);
    if(v2+1<=n/2) dfs(p+1,v1,v2+1,v3,hp+a[p][2]);
    if(v3+1<=n/2) dfs(p+1,v1,v2,v3+1,hp+a[p][3]);
}
signed main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout)
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        int a1m=-1,a2m=-1,a3m=-1;
        for (int i=1;i<=n;i++) {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            a1m=max(a1m,a[i][1]);
            a2m=max(a2m,a[i][2]);
            a3m=max(a3m,a[i][3]);
        }
        if (a2m==0&&a3m==0) {
            priority_queue<int> pq;
            for (int i=1;i<=n;i++) pq.push(a[i][1]);
            int ans=0;
            for (int i=1;i<=n/2;i++) {
                ans+=pq.top();
                pq.pop();
            }
            cout<<ans<<endl;
            continue;
        }
        dfs(1,0,0,0,0);
        cout<<ans<<"\n";
        ans=0;
        memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
/*
1
6
1 0 0
5 0 0
3 0 0
6 0 0
2 0 0
9 0 0
*/