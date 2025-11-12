#include<bits/stdc++.h>
using namespace std;
int n, m, seat[15][15], score[105];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i ++) cin >> score[i];
    int k = score[1], place, t0 = 0;
    sort(score + 1, score + 1 + n * m, cmp);
    for(int i = 1; i <= n * m; i ++) if(score[i] == k){place = i; break;}
    int r = place % n, col = place / n;
    if(r == 0){
        if(col % 2) cout << col << " " << n;
        else cout << col << " " << 1;
    }
    else{
        col ++;
        if(col % 2) cout << col << " " << r;
        else cout << col << " " << n - r + 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}