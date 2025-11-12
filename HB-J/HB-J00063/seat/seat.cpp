#include<bits/stdc++.h>

using namespace std;

struct Peo{
    int score, id;
}p[110];

int n, m;

bool cmp(Peo p1, Peo p2){
    return p1.score > p2.score;
}

int main(){

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n * m; i ++){
        p[i].id = i;
        scanf("%d", &p[i].score);
    }
    sort(p + 1, p + n * m + 1, cmp);
    int x = 1, y = 1, mv = 1;
    for(int i = 1; i <= n * m; i ++){
        if(p[i].id == 1){
            break;
        }
        if((mv == 1) && (x + 1 > n)){
            y = y + 1;
            mv = -1;
        }else if((mv == -1) && (x - 1 < 1)){
            y = y + 1;
            mv = 1;
        }else{
            x = x + mv;
        }
    }
    printf("%d %d\n", y, x);//xian lie zai hang
    return 0;
}