#include <iostream>
#include <cstdint>

using namespace std;

int n;

int max_goodscore = -1;

int current_goodscore;

int goodscore[114514][3];

// int8_t select[114514];

int club_mans[3];

void dfs(int depth){
    if(depth != n){
        for(int i = 0; i < 3; i++){
            if(club_mans[i] >= n/2) continue;
            // select[depth]=i;
            club_mans[i]++;
            current_goodscore += goodscore[depth][i];
            dfs(depth+1);
            current_goodscore -= goodscore[depth][i];
            club_mans[i]--;
        }
    }else{
        // top
        max_goodscore = max(max_goodscore, current_goodscore);
    }
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    cin >> T;

    while(T--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> goodscore[i][0] >> goodscore[i][1] >> goodscore[i][2];
        }
        dfs(0);
        cout << max_goodscore << endl;
        max_goodscore = 0;
    }
    
    return 0;
}