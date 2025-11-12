#include<bits/stdc++.h>
using namespace std;

int num[1000005];
bool cmp(int a, int b) {
    return a > b;
}

int main() {

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    int numi = 1;
    string a;
    cin >> a;

    for(int i = 0;i < a.size();i ++) {
        if(a[i] >= '0' && a[i] <= '9') {
            num[numi] = int(a[i] - '0');
            numi ++;
        }


    }

    sort(num + 1, num + numi + 1, cmp);
    for(int i = 1;i < numi;i ++) {
        printf("%d", num[i]);
    }


    return 0;
}
