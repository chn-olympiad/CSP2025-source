#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[105];
int b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n * m;i++){
        scanf("%d",&a[i]);
    }
    int c = a[1];
    sort(a,a + n * m + 1);
    int k = n * m;
    for(int i = 1;i <= n;i++){
        if(i % 2 != 0){
            for(int j = 1;j <= m;j++){
                b[i][j] = a[k];
                k--;
            }
        }else{
            for(int j = m;j >= 1;j--){
                b[i][j] = a[k];
                k--;
            }
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            if(b[i][j] == c){
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    return 0;
}
