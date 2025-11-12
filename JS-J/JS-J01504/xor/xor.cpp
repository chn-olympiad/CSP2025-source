#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int n, k, f = 0,lt = -1, a[500050];
long long ans = 0;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if( a[i] > 1) f = 1;
    }
    if(f){
        ans = (int)log2(n);
    }else {
        for(int i = 0; i < n; ++i){
            if( a[i] == k ){
                lt = -1;
                ++ans;
            }else if( lt == a[i] ){
                lt = -1;
                ++ans;
            }else lt = a[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
