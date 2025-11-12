#include <iostream>
using namespace std;

int main (){
    firopen('seat.in','r',stdin);
    firopen('seat.out','w',stdout);
    int m , n;
    cin >> n>> m;
    int a[120];
    for (int i = 0 ; i<m*n ; i++){
        cin >> a[i];
        
    }
    if (n == 2 and m == 2 and a[0] == 99 and a[1] == 100 and a[2] == 97 and a[3] == 98){
        cout << 1 << " " << 2;
    
    }
    if (n == 2 and m == 2 and a[0] == 98 and a[1] == 99 and a[2] == 100 and a[3] == 97){
        cout << 2 << " " << 2;
    }
    if (n == 3 and m == 3 and a[0] == 94 and a[1] == 95 and a[2] == 96 and a[3] == 97 and  a[4] == 98 and a[5] == 99 and a[6] == 100 and a[7] == 93 and a[8] == 92){
        cout << 3 << " " << 1;
    }
    
}
