#include <bits/stdc++.h>
using namespace std;
vector<int > vec;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++){
        int s;
        cin >> s;
        vec.push_back(s);
    }
    int cur = vec[0];
    sort(vec.begin(), vec.end(), cmp);
    int pm;
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] == cur){
            pm = i + 1;
            break;
        }
    }
    int c = pm / n;
    if (pm % n != 0){
        c++;
    }
    cout << c << ' ';
    if (pm % n == 0){
        if (c % 2 != 0){
            cout << m;
            return 0;
        }
        else if (c % 2 == 0){
            cout << 1;
            return 0;
        }
    }
    while (pm >= n){
        pm -= n;
    }
    if (c % 2 != 0){
        cout << pm;
    }
    else if (c % 2 == 0){
        cout << m - pm + 1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
