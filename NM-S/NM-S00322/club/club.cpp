#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t, n, max_, m1, m2, m3, flag1, flag2, flag3;

struct node{
    int s1;
    int s2;
    int s3;
}a[N];

struct node1{
    int sc;
    int num;
}m11[N];

struct node2{
    int sc;
    int num;
}m22[N];

struct node3{
    int sc;
    int num;
}m33[N];

struct node4{
    int g12;
    int g23;
    int g13;
}g[N];

bool cmp (int x, int y){
    return m11[x].sc < m11[y].sc;
}

bool c12 (int x, int y){
    return g[x].g12 < g[y].g12;
}

bool c23 (int x, int y){
    return g[x].g23 < g[y].g23;
}

bool c13 (int x, int y){
    return g[x].g13 < g[y].g13;
}

int main (){
    freopen ("club.in", 'r', stdin);
    freopen ("club.out", 'w', stdout);
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
            g[i].g12 = abs (a[i].s1 - a[i].s2);
            g[i].g23 = abs (a[i].s2 - a[i].s3);
            g[i].g13 = abs (a[i].s1 - a[i].s3);
            if (max (max (a[i].s1, a[i].s2), a[i].s3) == a[i].s1){
                m1++;
                m11[i].num = i;
                m11[i].sc = a[i].s1;
            }
            if (max (max (a[i].s1, a[i].s2), a[i].s3) == a[i].s2){
                m2++;
                m22[i].num = i;
                m22[i].sc = a[i].s2;
            }
            if (max (max (a[i].s1, a[i].s2), a[i].s3) == a[i].s3){
                m3++;
                m22[i].num = i;
                m33[i].sc = a[i].s3;
            }
            max_ += max (max (a[i].s1, a[i].s2), a[i].s3);
        }
        int flag = 0;
        for (int i = 1; i <= n; i++){
            if (a[i].s1 == 0) flag1++;
            if (a[i].s2 == 0) flag2++;
            if (a[i].s3 == 0) flag3++;
        }
        /*
        if (flag1 == n){
            sort (g + 1, g + 1 + n, c23);
            for (int i = 1; i <= n / 2; i++){
                max_ -= g[i].g23;

            }
        }
        sort (m11 + 1, m11 + 1 + n, cmp);
        sort (m22 + 1, m22 + 1 + n, cmp);
        sort (m33 + 1, m33 + 1 + n, cmp);
        for (int i = 1; i <= n / 2; i++){
            if (m1 > n / 2){

            }
            if (m2 > n / 2){

            }
            if (m3 > n / 2){

            }
        }
        */
        cout << max_;
    }
    return 0;
}
