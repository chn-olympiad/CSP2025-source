#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[201];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n * m; i++){
        scanf("%d",&a[i]);
    }
    int r = a[1];
    int p = 0;
    sort(a + 1,a + n * m + 1);
    for(int i = 1; i <= n * m; i++){
        if(a[i] == r){
            p = n * m - i + 1;
            i += 101;
        }
    }
    int x = 1,y = 0;
    for(int i = 1; i <= p; i++){
        if(x % 2 == 1){
            y++;
            if(y > n) x++,y = n;
        }else{
            y--;
            if(y == 0) x++,y = 1;
        }
    }
    printf("%d %d\n",x,y);
    return 0;
}
