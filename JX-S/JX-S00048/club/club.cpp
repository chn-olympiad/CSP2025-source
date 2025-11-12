
#include <bits/stdc++.h>
using namespace std;

int turn, n, person[10001][3], club[3];
int ans = -1;
int max_p = 0;

void dfs(int p, int a){
    if(a > ans) ans = a;
    for(int i = 0; i < 3; i++){
        if(club[i] > max_p-1) continue;
        club[i]++;
        if(p < n) dfs(p+1, a+person[p][i]);
        club[i]--;
    }
}

int too_much(){
    int a = 0, tmp = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3;j++){
            tmp = max(tmp, person[i][j]);
        };
        a += tmp;
        tmp = -1;
    }
    return a;
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>turn;
    while(turn--){
        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 3;j++) cin>>person[i][j];
        }
        max_p = n / 2;
        if(n < 30) dfs(0, 0);
        else ans = too_much();
        cout<<ans<<endl;
        ans = -1;
    }

    return 0;
}
