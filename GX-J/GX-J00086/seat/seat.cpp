#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int score[105], m, n, R;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int s = m * n;
    for(int i = 0; i < s; i++) cin >> score[i];
    R = score[0];
    sort(score, score + s, cmp);
    int Ri;
    for(int i = 0; i < s; i++){
        if(score[i] == R) Ri = i;
    }
    if((Ri / n) % 2 == 0){
        cout << (Ri / n) + 1 << " " << Ri % n + 1;
    }
    else{
        cout << Ri / n + 1 << " " << n - Ri % n;
    }
    return 0;
}
