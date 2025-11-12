#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int a[maxn],b[maxn][maxn];
int n,m;

bool cmp(int x,int y){
    return x > y;
}
queue<pair<int,int> > q;
void bfs(){
    q.push({1,1});
    int idx = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        b[x][y] = a[idx ++];
        if(y & 1){
            if(x < n) q.push({x + 1,y});
            else if(y + 1 <= n){
                q.push({x,y + 1});
            }
        }
        else{
            if(x > 1) q.push({x - 1,y});
            else if(y + 1 <= n) q.push({x,y + 1});
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n * m ; i ++){
        cin >> a[i];
    }
    int num = a[1];
    sort(a + 1,a + 1 + n * m,cmp);
    bfs();
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= m ; j ++){
            if(b[i][j] == num) {
                cout << j << ' ' << i;
                return 0;
            }
        }
    }
}