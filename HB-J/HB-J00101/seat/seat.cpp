#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
    int n , m , c = 0;
    int a[109] = {};
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
        if(a[i] > a[1]){
            c++;
        }
    }
    c += 1;
    if(c % n == 0){
        if((c / n) % 2 == 1){
            if(c % n == 0){
                cout << c / n << " " << 2;
            }else{
               cout << c / n << " " << c % n;
           }
        }else if((c / n) % 2 == 0){
            cout << c / n << " " << n - c % n;
        }
    }else{
        if((c / n + 1) % 2 == 1){
            if(c % n + 1 == 0){
                cout << c / n + 1 << " " << 2;
            }else{
               cout << c / n + 1 << " " << c % n;
           }
        }else if((c / n + 1) % 2 == 0){
            cout << c / n + 1 << " " << n - c % n + 1;
        }
    }
	return 0;
}
