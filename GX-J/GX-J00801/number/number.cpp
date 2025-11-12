#include <bits/stdc++.h>

using namespace std;
string str, res;
int ct[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> str;
    for (char& c : str){
        if (isdigit(c)){
            ct[c-'0']++;
        }
    }

    for (int i = 9; i >= 1; i--){
        while (ct[i]--){
            res.push_back(i+'0');
        }
    }
    if (res.empty())res = "0";
    else {
        while (ct[0]--){
            res.push_back('0');
        }
    }
    cout << res;
    return 0;
}
