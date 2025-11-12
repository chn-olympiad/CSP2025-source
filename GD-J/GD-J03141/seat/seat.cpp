#include <bits/stdc++.h>

using namespace std;
vector<int> score;
int r_s;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    score.resize(n * m);
    for(int i = 0;i < n * m;i++){
        int a;
        cin >> a;
        score[i] = a;
    }
    r_s = score[0];
    sort(score.begin(), score.end());
    int f = 0;
    for(int i = n * m - 1;i >= 0;i--){

        if(score[i] == r_s){
            f = n * m - i;
        }
    }
    int b = f, j = 1;
    while(b > n){
        b -= n;
        j++;
    }
    if(j % 2 == 0) printf("%d %d", j, n - b + 1);
    else printf("%d %d", j, b);
}
