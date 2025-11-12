#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in", "r",stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int a{100000};
    for (int i = 0;i <= s[8];i++)
    {
        if(s[i] >= 1 && s[i] <= 9){
            a = i;
        }
    }
    cout << a;
    return 0;
}
