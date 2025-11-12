#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b ) {
    return a > b;
}

vector<int>vec;
int main () {
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 1; i <= s.size(); i++) {
        if ('0'<=s[i]&&s[i]<='9')  {
            int z;
            z=(int)s[i]-'0';
            vec.push_back(z);
            cnt++;
        }
    }
    sort (vec.begin(),vec.end(), cmp);

    for (int i = 1; i <= cnt; i++) {
        cout << vec[i];
    }
    return 0;
}
