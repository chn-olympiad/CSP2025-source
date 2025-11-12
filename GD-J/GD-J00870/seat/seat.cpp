#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    const int PPL = n * m;
    vector<int> a(PPL, 0);
    for(int i = 0; i < PPL; i++){
        cin >> a[i];
    }
    int r_grade = a[0], r_place = 0;;
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i < PPL; i++){
        if(a[i] == r_grade){
            r_place = i + 1;
            break;
        }
    }
    int row, lie = (r_place + n - 1) / n, tmp = r_place - (lie - 1) * n;;
    if(lie % 2 == 1){
        cout << lie << " " << tmp;
        return 0;
    }
    cout << lie << " " << n - tmp + 1;
    return 0;
}