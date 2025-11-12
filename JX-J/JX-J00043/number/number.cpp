#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int cnt[N] , p=0;

bool cmp(int a , int b) {
    return a > b;
}

int main() {
    string a;
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    cin>>a;
    for (int i=0;i<a.size();i++) {
        if (a[i] >= '0' && a[i] <= '9') {
            p ++;
            cnt[p] = a[i] - '0';
        }
    }
    sort(cnt + 1 , cnt + p + 1 , cmp);
    for (int i=1;i<=p;i++) {
        cout<<cnt[i];
    }
    return 0;
}
