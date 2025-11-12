#include <bits/stdc++.h>
using namespace std;
struct node{
    int score, id;
    int col, row;
}a[100005];
bool cmp(node x, node y){
    return x.score > y.score;
}
int n, m, idx;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i].score;
        a[i].id = i;
    }
    sort(a + 1,a + n * m + 1, cmp);
    int i = 0, j = 1, idx = 1;
    while(idx <= n * m && j <= m){ //i:row j:col
        while(i < n){
            i++;
            a[idx].row = i, a[idx].col = j;
            idx++;
        }
        j++, i++;
        while(i > 1){
            i--;
            a[idx].row = i, a[idx].col = j;
            idx++;
        }
        j++, i--;
    }
    for(int k = 1; k <= n * m; k++){
        if(a[k].id == 1){
            cout << a[k].col << ' ' << a[k].row;
            break;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
