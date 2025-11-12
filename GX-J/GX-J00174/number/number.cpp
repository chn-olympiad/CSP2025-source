#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010],top;
int main(){
    freopen("w","number.in",stdin);
    freopen("r","number.out",stdout);
    cin >> s;
    for (auto y : s){
        if (y >= '0' && y <= '9') a[++top] = y - '0';
    }
    sort(a + 1,a + top + 1);
    for (int i = top;i > 0;i--) cout << a[i];
    return 0;
}
