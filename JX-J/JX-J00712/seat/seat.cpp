#include<bits/stdc++.h>
using namespace std;

int n, m, a[101];

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
        cin >> a[i];
    int x = a[1], y = n * m;
    for (int i = 1; i <= y - 1; i++)
        for (int j = 1; j <= y - i; j++)
            if (a[j] < a[j + 1])
                swap(a[j], a[j + 1]);
    int c, r;
    for (int i = 1; i <= y; i++){
        if(a[i] == x){
            if (i % n == 0) {
                c = i / n;
            }
            else
                c = i / n + 1;
            if (c % 2 == 1)
                if (i % n == 0)
                    r = n;
                else
                    r = i % n;
            else
                if (i % n == 0)
                    r = 1;
                else
                    r = n - (i % n) + 1;
        break;
        }

    }
    printf("%d %d", c, r);
    return 0;
}
