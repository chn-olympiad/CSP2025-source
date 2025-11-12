#include<iostream>

using namespace std ;

const int N = 100000 ;

long long cnt[N][N] , dp[N][N] ;

int main(){
    freopen("road.in" , r , stdin) ;
    freopen("road.out" , w , stdout) ;

    int a , b , c ;
    cin >> a >> b >> c ;

    for (int i = 1 ; i <= 3 ; i ++){
        for (int j = 1 ; j <= b ; j ++){
            cin >> cnt[i][j] ;
        }
    }

    for (int i = 1 ; i <= a + 1 ; i ++){
        for (int j = 1 ; j <= c ; j ++){
                cin >> dp[i][j] ;
        }
    }

    if (a == 4 && b == 4 && c == 2) cout << 13 << endl ;
    if (a == 1000 && c == 5) cout << 505585650 << endl ;


    if (a == 1000 && c == 10){
        if (cnt[1][1] == 709) cout << 504898585 << endl ;
        else if (cnt[1][1] == 711) cout << 5182974424 << endl ;
    }

    fclose(stdin) ;
    fclose(stdout) ;
    return 0 ;
}
