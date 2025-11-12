# include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n,m,a, pos;
    scanf("%d %d", &n, &m);
    int total = n * m, s[n * m + 5], b[n + 5][m + 5];
    for(int i = 1; i <= total; i++){
        scanf("%d", &s[i]);
    }
    a = s[1];
    for(int i = 1; i <= total; i++){
        if(s[i] < s[i+1]){
            int temp = s[i];
            s[i] = s[i+1];
            s[i+1] = temp;
        }
    }
    for(int i = 1; i <= total; i++){
        if(s[i] == a){
            pos = i;
        }
    }
    int x = 1;
    while(pos > n){
        pos = pos - n;
        x++;
    }

    if(x % 2 == 0){
        printf("%d %d", x, n - pos + 1);
    }
    else{
        printf("%d %d", x, pos);
    }

    return 0;
}
