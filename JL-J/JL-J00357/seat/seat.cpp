#include <bits/stdc++.h>
using namespace std;
struct node{
    int score;
    bool flag;
};
vector<node> a;
bool cmp(node x, node y){
    return x.score > y.score;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++){
        int k;
        cin >> k;
        a.push_back({k, (i == 1)});
    }
    sort(a.begin(), a.end(), cmp);
    int id;
    for (int i = 0; i < a.size(); i++){
        if (a[i].flag){
            id = i + 1;
            break;
        }
    }
    if (id % n == 0){
        int c = id / n;
        cout << c;
        if (c % 2 == 0)
            cout << 1;
        else
            cout << n;
    } else {
        int c = id / n + 1, k = id % n;
        cout << c << " ";
        if (c % 2 == 0)
            cout << n - k + 1;
        else
            cout << k;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
