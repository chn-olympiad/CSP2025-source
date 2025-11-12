#include<iostream>
using namespace std;
int n,m,a[10010][10010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cout << n << endl;
    return 0;
}