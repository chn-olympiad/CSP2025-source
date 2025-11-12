#include <bits/stdc++.h>
using namespace std;
int s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    if(s<=10){cout << s;return 0;}
    for (int i = 1; i <= s;i++){
        s=max(s,0);
    }
    cout << s;
    return 0;
}
