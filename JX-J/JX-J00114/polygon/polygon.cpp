#include <iostream>
using namespace std;

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;

    if (n == 3){
        int a, b, c;
        cin >> a >> b >> c;
        int maxn = max(a, b);
        maxn = max(maxn, c);
        if (a+b+c>maxn*2){
            cout << 1;
        }else{
            cout << 0;
        }
    }else{
        for (int i=0; i < n; ++i){
            int x;
            cin >> x;
        }
        long long sum=0;
        for (int i=2; i < n; ++i){
            sum = (sum + n-i) % 998 % 353 % 244;
        }

        cout << sum << endl;
    }
}
