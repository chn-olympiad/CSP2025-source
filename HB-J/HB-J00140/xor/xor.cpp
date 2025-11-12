#include <iostream>
using namespace std;
int n, k, cnt;
int ra[500005];
int main(){
    freopen("xor.in", 'r', stdin);
    freopen("xor.out", 'w', stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
        cin >> ra[i];
    if (k == 0){
        for (int i = 0; i < n; i ++)
            if (ra[i] == 0)
                cnt ++;
    }
    else if (k == 1){
        for (int i = 0; i < n; i ++)
            if (ra[i] == 0)
                cnt ++;
    }
    cout << cnt;
    return 0;
}
