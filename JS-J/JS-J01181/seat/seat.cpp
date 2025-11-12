#include <bits/stdc++.h>

using namespace std;

struct Node{
    int idx;
    int sc;
};

bool cmp(Node x, Node y){
    return x.sc > y.sc;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;

    vector<Node> a(n * m);
    for (int i = 0; i < n * m; ++i){
        cin >> a[i].sc;
        a[i].idx = i;
    }

    sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < a.size(); ++i){
        if (a[i].idx == 0){
            int x = i;
            if ((x / n) % 2 == 0){
                cout << x / n + 1 << ' ' << x % n + 1 << endl;
            }
            else{
                cout << x / n + 1 << ' ' << n - x % n << endl;
            }
            break;
        }
    }
    return 0;
}