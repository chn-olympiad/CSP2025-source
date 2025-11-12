#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int t,n;
int a[100005][5],cnt[5];
bool vis[100005];
struct node{
    int x,y,z;
    bool operator < (const node &b) const{
        return x<b.x;
    }
};
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        priority_queue<node> que;
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            int maxx = 0;
            for(int j=1;j<=3;j++){
                cin >> a[i][j];
                maxx = max(maxx,a[i][j]);
            }
            que.push({a[i][1]-max(a[i][2],a[i][3]),1,i});
            que.push({a[i][2]-max(a[i][1],a[i][3]),2,i});
            que.push({a[i][3]-max(a[i][2],a[i][1]),3,i});
//            for(int j=1;j<=3;j++){
//                que.push({a[i][j],j,i});
//                cout << a[i][j]-maxx << " " << j << " " << i << endl;
//            }
        }
        int ans = 0;
        while(!que.empty()){
            node x = que.top();
            que.pop();
            if(cnt[x.y]<n/2 && !vis[x.z]){
                cnt[x.y]++;
                vis[x.z] = 1;
                ans+=a[x.z][x.y];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1

(2,1,1)*
(-2,2,1)*
(-3,3,1)*
(-1,1,2)*
(-2,1,2)*
(1,3,2)*
(1,1,3)*
(-2,2,3)*
(-1,3,3)*
(-2,1,4)*
(2,2,4)*
(-4,3,4)*

1:1 3
2:4
3:2

*/
