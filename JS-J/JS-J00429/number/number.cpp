#include <bits/stdc++.h>

using namespace std;

string s;

int n, h[110];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> s;
    n = s.size();
    for(int i = 0;i < n;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            h[s[i] - '0']++;
        }
    }
    for(int i = 9;i >= 0;i--){
        while(h[i]--){
            cout << i;
        }
    }
    cout << endl;

    return 0;
}