#include <cstdio>
#include <algorithm>
using namespace std;
int a[110];
int fx = 1;
int x = 1 , y = 1;
int t;
int cnt = 1;
int n , m;
bool in(int x , int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
bool cmp(int a , int b){
    return a > b;
}
int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    scanf("%d%d" , &n , &m);
    for(int i = 1 ; i <= n * m ; i++) scanf("%d" , &a[i]);
    t = a[1];
    sort(a + 1 , a + n * m + 1 , cmp);
    for(int i = 1 ; i <= n * m ; i++){
        if(a[i] == t){
            t = i;
            break;
        }
    }
    for(int i = 1 ; i <= n * m ; i++){
        x += fx;
        if(!in(x , y)){
            x -= fx;
            y++;
            fx = -fx;
        }
        cnt++;
        if(cnt == t){
            printf("%d %d" , y , x);
            return 0;
        }
    }
    return 0;
}
