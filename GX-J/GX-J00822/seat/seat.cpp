#include <iostream>
using namespace std;
int n, m, k;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    int ai = a[1];
    for(int i = 2; i<= n* m; i++){
            for(int j = 1; j <= n*m; j++){
            if(a[j]< a[i]){
                int b = a[j];
                a[j] = a[i];
                a[i] = b;
            }
            }

    }
    for(int i = 1; i <= n * m; i++){
        if(a[i] == ai){
            k = i;
            //cout << i;
            break;
        }
    }
    int c = 1 , r =1;
    if(k % n != 0){
        c = k / n + 1;
    }else{
        c = k / n;
    }
    if(c % 2 == 0){
        if(k % n !=0)
            r = n + 1 - k % n;
    }else{
        if(k % n != 0)
            r = k % n;
        else
            r = n;
    }
    cout << c << " " << r;

    return 0;
}
