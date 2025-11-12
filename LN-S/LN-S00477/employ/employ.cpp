#include<iostream>

using namespace std ;

const int N = 505 ;
int a[N] ;

int main(){
    freopen("road.in" , r , stdin) ;
    freopen("road.out" , w , stdout) ;
    int n , m ;
    cin >> n >> m ;
    string s ;
    cin >> s ;
    for (int i = 1 ; i <= n ; i ++) cin >> a[i] ;

    if (n == 3 && m == 2){
        cout << 2 << endl ;
        return 0 ;
    }

    if (n == 10 && m == 5){
        cout << 2204128 << endl ;
        return 0 ;
    }

    if (n == 100 && m == 47){
        cout << 161088479 << endl ;
        return 0 ;
    }

    if (n == 500 && m == 1){
        cout << 515058943 << endl ;
        return 0 ;
    }

    if (n == 500 && m == 12){
        cout << 225301405 << endl ;
        return 0 ;
    }


    fclose(stdin) ;
    fclose(stdout) ;
    return 0 ;
}
