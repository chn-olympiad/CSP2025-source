#include <bits/stdc++.h>
using namespace std;
int n, m , a[105], c[20][20], ans;
bool cmp(int x, int y){
    return x>y;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n*m; i++){
        scanf("%d", &a[i]);
    }
    ans=a[1];
    sort(a+1, a+n*m+1, cmp);
    int s=1;
    //cout << ans << ' ';
    for (int i=1; i<=m; i++){
        if (i%2==1){
            for (int j=1; j<=n; j++){
                c[j][i]=a[s];
                s++;
            }
        }else{
            for (int j=n; j>=1; j--){
                c[j][i]=a[s];
                s++;
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
			//cout << c[i][j] << ' ';
            if (c[i][j]==ans){
				printf("%d %d", j, i);
                return 0;
			}
        }
    }
    return 0;
}
