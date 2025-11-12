#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];
int s;
int seat[15][15];
int i, j, k=1;
int dx[]={0, 1, -1, 0};
int dy[]={0, 0, 0, 1};
bool b;
void digui(int x, int y) {
    seat[x][y]=a[k];
    k++;
    for(i=1; i<=3; i++) {
        if(x+dx[i]>=1&&x+dx[i]<=n&&y+dy[i]>=1&&y+dy[i]<=m&&seat[x+dx[i]][y+dy[i]]==0) {
            digui(x+dx[i], y+dy[i]);
            break;
        }
    }
    return;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i=1; i<=n*m; i++) {
        scanf("%d", &a[i]);
        if(i==1) {
            s=a[i];
        }
    }
    for(i=1; i<n*m; i++) {
            b=true;
        for(j=n*m; j>i; j--) {
            if(a[j]>a[j-1]) {
                swap(a[j], a[j-1]);
                b=false;
            }
        }
        if(b) {
            break;
        }
    }
    digui(1, 1);
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(seat[i][j]==s) {
                    printf("%d %d", j, i);
                break;
            }
        }
    }
    return 0;
}
