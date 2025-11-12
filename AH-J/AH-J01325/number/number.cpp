#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main(){
    freopen("numuber.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for (int i=0;i<s.length();i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            string s2;
            s2=s[i];
            int is;
            is=atoi(s2.c_str());
            a.push_back(is);
        }
    }
    sort(a.begin(),a.end());
    int n=a.size()-1;
    if (a[n] != 0) {
        for (int i=n;i>=0;i--) {
            cout << a[i];
        }
    } else {
        cout << 0;
    }
    cout <<endl;
    return 0;
}
