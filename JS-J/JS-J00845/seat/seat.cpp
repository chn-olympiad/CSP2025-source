#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int tmp=1;
    int rx;
    cin >> rx;
    for(int i = 1;i < n*m;i++){
        int x;
        cin >> x;
        if(x > rx){
            tmp++;
        }
    }
    int ansn = ceil(1.0*tmp/n);
    cout << ansn << ' ';
    if(ansn % 2 == 0){
        if(tmp % m == 0){
            cout << 1;
        }else{
            cout << m-tmp%m+1;
        }
    }else{
        if(tmp % m == 0){
            cout << m;
        }else{
            cout << tmp%m;
        }
    }
    return 0;
}
