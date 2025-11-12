#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w", stdout);
    int n, m;
    cin >> n >> m;
    int b[n+1][m+1], xr;
    vector <int> a;
    for(int i = 0; i < n*m; i++){
        int f;
        cin >> f;
        if(i == 0) xr = f;
        a.push_back(f);
    }
    sort(a.begin(), a.end(), [](int a, int b){return a > b;});
    int c = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(i % 2 != 0){
                b[j][i] = a[c];
                if(a[c] == xr) cout << i << " " << j <<endl;
            }
            else{
                b[n-j+1][i] = a[c];
                if(a[c] == xr) cout << i << " " << n-j+1 <<endl;
            }
            if(c < a.size()) c++;
        }
    }
    return 0;
}
