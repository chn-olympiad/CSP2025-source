#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define endl "\n"
string s;
int a[1010];
int main(){
    IOS
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (int i = 0 ; i <= s.size() ; i ++ )
        if (s[i] >= '0' && s[i] <= '9') a[s[i] - '0'] += 1;
    for (int i = 9 ; i >= 0 ; i -- )
        while (a[i] > 0) {
            a[i] -= 1;
            cout << i;
        }
    return 0;
}
