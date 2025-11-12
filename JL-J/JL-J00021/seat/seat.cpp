#include <bits/stdc++.h>
using namespace std;
int score[150];
int seat[12][12];
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int r_c;
    int now_x = 1, now_y = 1;
    bool sy = true;
    for(int i = 1; i <= n*m; i++){
        cin >>score[i];
    }
    r_c = score[1];
    sort(score+1, score+n*m +1, cmp);
    int pos;
    for(int i = 1; i <= n*m; i++){
        if(score[i] == r_c){
            pos = i;
        }
    }
    now_x = ceil(pos*1.0/n);
    if(now_x % 2 == 0){
        int temp = pos % n;
        if(temp == 0) temp = n;
        now_y = n - temp + 1;
    }
    else if(now_x % 2 == 1){
        int temp = pos % n;
        if(temp == 0) temp = n;
        now_y = temp;
    }
    cout << now_x <<" " << now_y;
    return 0;
}
