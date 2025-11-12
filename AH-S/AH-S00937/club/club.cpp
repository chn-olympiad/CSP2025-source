#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N][3],n;
struct node{
    int x,d1,d2,d3;
}f[N][3];
int mx = 0;
void dfs(int x,int d1,int d2,int d3,int sum){
    if (x == n+1){
        mx = max(mx,sum);
        return;
    }
    if (d1 < n/2) dfs(x+1,d1+1,d2,d3,sum+a[x][1]);
    if (d2 < n/2) dfs(x+1,d1,d2+1,d3,sum+a[x][2]);
    if (d3 < n/2) dfs(x+1,d1,d2,d3+1,sum+a[x][3]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t = 0;
    scanf("%d",&t);
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= 3;++j){
                scanf("%d",&a[i][j]);
            }
        }
        if(n <= 10){
            mx = 0;
            dfs(1,0,0,0,0);
            cout << mx << "\n";
        }else{
            priority_queue<int> q;
            for(int i = 1;i <= n;++i) q.push(max({a[i][1],a[i][2],a[i][3]}));
            int sum = 0;
            for(int i = 1;i <= n/2;++i){
                sum += q.top();
                q.pop();
            }
            cout << sum << "\n";
        }
    }
    return 0;
}
