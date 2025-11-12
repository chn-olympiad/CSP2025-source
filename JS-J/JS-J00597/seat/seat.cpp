#include <bits/stdc++.h>
using namespace std;
int n,m,peo,num,ans;
const int N = 110;
int mark[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    peo = n*m;
    for (int i = 1; i<= peo;i++){
        cin >> mark[i];
    }
    num = mark[1];
    sort(mark+1,mark+peo+1);
    for (int i = peo;i >= 1;i--){
        if(mark[i] == num){
            ans = peo-i+1;
            break;
        }
    }
    int k1,k2;
    if (!(ans%n)){
        k1 = ans / n;
    }
    else{
        k1 = ans/n+1;
    }

    if (k1%2 == 1){
        if (!(ans%n)){
            k2 = n;
        }
        else{
            k2 = ans%n;
        }
    }
    else{
        if (!(ans%n)){
            k2 = 1;
        }
        else{
            k2 = n+1-ans%n;
        }
    }
    cout << k1 << " " << k2 << '\n';
    return 0;
}
