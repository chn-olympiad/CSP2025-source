#include <bits/stdc++.h>
using namespace std ;
struct node{
    int score,id;
};
bool cmp(node x,node y){
    return x.score > y.score ;
}
int a[100001]  ;
int mp[15][15] ;
int main(){
    freopen("seat.in","r",stdin) ;
    freopen("seat.out","w",stdout) ;
    int n,m ;
    scanf("%d%d",&n,&m) ;
    for(int i = 1; i <= n*m ; i++){
        scanf("%d",&a[i]) ;
    }
    int s = a[1];
    sort(a+1,a+n*m+1,greater<int>()) ;
    int i = 1 ;
    int x = 1 ;
    int  y = 1 ;
    while(i <= n * m){
        mp[x][y] = a[i] ;
        if( y % 2 == 0 ){
            if(x == 1){
                y+=1 ;
            }else{
                x+=-1 ;
            }
        }else if( y % 2 == 1){
            if(x == n){
                y+=1 ;
            }else{
                x+=1 ;
            }

        }
        i+=1 ;
    }
    int fx , fy ;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mp[i][j] == s){
                fx = i ;
                fy = j ;
                break ;
            }
        }
    }
    printf("%d %d",fy,fx) ;
    return 0;
}
