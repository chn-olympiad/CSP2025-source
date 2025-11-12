#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, m;
int arr[N * N];
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i ++){
        cin >> arr[i];
    }
    int nf = arr[1];
    sort(arr + 1, arr + 1 + n * m, [&](int _, int __){
            return _ > __;
         });
    int i = 1, j = 1;
    for(int i = 1;i <= n * m;i ++){
        if(arr[i] == nf){
            int line = (i + n - 1) / n;
            int col = i % m;
            if(col == 0){
                col = m;
            }
            if(line % 2 == 0){
                col = m - col + 1;
            }
            cout << line << " " << col << endl;
            return 0;
        }
    }

    return 0;
}
