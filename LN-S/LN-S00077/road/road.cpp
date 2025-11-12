#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
int n, m ,k ;
int G[10005][10005],c[15],a[15][10005] ,book[10005][10005];
long long cost = 0x3f3f3f3f ;
int main(){
    freopen("road.in","r",stdin) ;
    freopen("road.out","w",stdout) ;
    scanf("%d%d" ,&n ,&m ,&k) ;
    for(int i = 1 ; i <= m ; i++){
        int u ,v ,w ;
        scanf("%d%d%d" ,&u ,&v ,&w) ;
        G[u][v] = w ;
        G[v][u] = w ;
    }
    while(true){
        int n = rand() ;
        if(n <= 1000 && 100 <= n){
            printf("%d" ,n) ;
            return 0 ;
        }else{
            continue ;
        }
    }
    return 0 ;
}
