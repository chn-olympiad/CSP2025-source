//AH-J01482 Eason Cyj001001
#include "bits/stdc++.h"
#define int long long

using namespace std;
const int N = 10 + 5;
int n,m;
int x;
int v;
int a[N*N];
int p[N][N];

bool cmp(int x,int y){
	return x>y;
}

signed main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> a[++x];
            v = a[1];
        }
    }
    sort(a+1,a+x+1,cmp);
    int i=1,j=1;
    for(int k=1; k<=n*m; k++) {
        p[i][j] = a[k];
        if(j%2 == 1) {
            i++;
        }else{
            i--;
        }
        if(i == n+1) {
            i = n;
            j++;
        }
        if(i == 0) {
            i = 1;
            j++;
        }
    }
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++) {
            if(p[i][j] == v) {
                cout << j << " " << i;
                return 0;
            }
        }
    }
}
