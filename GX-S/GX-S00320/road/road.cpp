#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10 ;
int n , m , k , x , y , z , f[maxn] , tot ;
long long ans ;
struct node{
    int x , y , len ;
    bool operator < ( const node &other ) const{
        return len < other.len ;
    }
}edge[maxn];
int find ( int x ){
    if ( x == f[x] ) return x ;
    return f[x] = find(f[x]) ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k ;
    for ( int i = 1 ; i <= m ; i++ ){
        scanf("%d%d%d",&x,&y,&z);
        edge[++tot] = (node){x,y,z};
        edge[++tot] = (node){y,x,z};
    }
    sort ( edge + 1 , edge + 2 * m + 1 ) ;
    for ( int i = 1 ; i <= n ; i++ ) f[i] = i ;
    for ( int i = 1 ; i <= 2 * m ; i++ ){
        x = edge[i].x , y = edge[i].y , z = edge[i].len ;
        x =find(x) , y = find(y) ;
        if ( x != y ){
            f[x] = y ;
            ans+=z;
        }
    }
    cout << ans << endl ;
    return 0 ;
}
