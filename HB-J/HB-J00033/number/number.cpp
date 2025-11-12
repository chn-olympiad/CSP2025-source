#include <bits/stdc++.h>
using namespace std;

string s;
int l, a[1000005];

bool cmp(int a, int b){
    return a > b;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    l = s.size();
    int f = 1;
    for (int i = 0; i < l; i++){
        if ('0' <= s[i] && s[i] <= '9'){
            a[f] = s[i] - '0';
            f++;
        }
	}
    sort(a + 1, a + f, cmp);
    /*for (int i = 1; i < f; i++){
        cout << a[i] << " ";
    }*/
    for (int i = 1; i < f; i++){
        cout << a[i];
    }
    return 0;
}
