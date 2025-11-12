#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+8;
int n;
int limi;
int a[N][4];
bool vis[N][4];
int e[4],cnt[4];
int ans;
int T;
priority_queue <int> q1;

void dfs(int x){
    if(x == n+1){
        ans = max(ans,e[1]+e[2]+e[3]);
        return ;
    }

    for(int i = 1; i <= 3; i++){
        if(!vis[x][i] && cnt[i] < limi){
            vis[x][i] = 1;
            cnt[i] ++;
            e[i] += a[x][i];

            dfs(x+1);

            vis[x][i] = 0;
            cnt[i]--;
            e[i] -= a[x][i];


        }
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >>T;

    while(T--){
        cin >> n;
        limi = n/2;
        ans = 0;
        e[1]=e[2] = e[3] = 0;
        cnt[1]=cnt[2]=cnt[3] = 0;
        for(int i=1; i <= n; i++){
            for(int j = 1; j <= 3; j++){
                cin >> a[i][j];
            }
        }

        dfs(1);

        cout << ans << endl;
    }

    return 0;
}



