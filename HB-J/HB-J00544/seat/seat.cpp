#include <cstdio>

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    int sort[101] = {0};
    int scoreIM;
    for (int i = 0; i < n*m; i++) {
        int k;
        scanf("%d",&k);
        if (i == 0) {
            scoreIM = k;
        }
        sort[k]++;
    }

    int id=1;
    for (int i = 100; i > scoreIM; i--) {
        id += sort[i];
    }

    int row = (id - 1) / n + 1;
    int rowFirst = (row - 1) * n + 1;
    int column;
    if (row % 2 == 1) {
        column = 1 + (id - rowFirst);
    } else {
        column = n - (id - rowFirst);
    }
    printf("%d %d",row,column);
    return 0;
}