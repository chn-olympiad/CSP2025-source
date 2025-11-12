#include <iostream>
#include <algorithm>
using namespace std;

int score[105];

bool cmp(int a, int b){
    return a > b;
}

int main(){

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n * m; i++){
        cin >> score[i];
    }
    int s_score = score[0];

    sort(score, score + n * m, cmp);

// for (int i=0; i<n*m; i++){cout << score[i] << ' ';}

    int seat;
    for (int i = 0; i < n * m; i++){
        if (score[i] == s_score){
            seat = i;
        }
    }

    int seat_col = seat / m;
    int seat_row = 0;
    if (seat_col % 2 == 0){
        seat_row = seat - seat_col * m ;
    }
    else {
        seat_row = n - 1 - (seat - seat_col * m);
    }

    cout << seat_col + 1 << ' ' << seat_row + 1;
    cout << endl;
    return 0;
}