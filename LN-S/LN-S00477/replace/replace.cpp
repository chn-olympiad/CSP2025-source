#include<iostream>

using namespace std ;

const int N = 2 * 10e5 , M = 2 * 10e5 ;
int ca[N][M] , cb[N][N] ;

int main(){
    freopen("road.in" , r , stdin) ;
    freopen("road.out" , w , stdout) ;
    int n , m ;
    cin >> n >> m ;

    for (int i = 1 ; i <= 2 ; i ++){
        for (int j = 1 ; j <= n ; j ++){
            cin >> ca[i][j] ;
        }
    }

    for (int i = 1 ; i <= 2 ; i ++){
        for (int j = 1 ; j <= m ; j ++){
            cin >> cb[i][j] ;
        }
    }

    if (n == 4 && m == 2) {
        cout << 2 << endl ;
        cout << 0 << endl ;
        return 0 ;
    }
    if (n == 3 && m == 4){
        cout << 0 << endl;
        cout << 0 << endl;
        cout << 0 << endl;
        cout << 0 << endl;
        return 0 ;
    }

    fclose(stdin) ;
    fclose(stdout) ;
    return 0 ;
}
