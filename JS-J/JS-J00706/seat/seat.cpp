#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int m,n,a[105],s;

bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)cin >> a[i];
    s = a[1];
    sort(a + 1,a + m*n + 1,cmp);
    for(int i = 1;i <= m*n;i++){
        //cout << i << " :" << a[i] << endl;
        if(a[i] == s){
            int b,c = i / n + 1;
            if(i % n == 0){
                c -= 1;
                if((i / n)%2 == 0){
                    b = 1;
                }else{
                    b = n;
                }
            }
            else if((i / n + 1) % 2 == 0){
                b = n - (i % n) + 1;
            }else{
                b = i % n;
            }
            cout << c << " " << b;
            break;
        }
    }
    return 0;
}

