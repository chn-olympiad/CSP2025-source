#include <bits/stdc++.h>
using namespace std;

int m, n;
int a,scr;
int id;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    cin >> scr;
    for (int i = 1; i < m * n; i++)
    {
        cin >> a;
        if(a>scr)
            id++;
    }
    cout << id / n + 1 << " ";
    if(id/n%2==0)
        cout << id % n + 1;
    else
        cout << n - id % n;
    cout << endl;
    return 0;
}