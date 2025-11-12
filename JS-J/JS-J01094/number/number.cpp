#include<bits/stdc++.h>
using namespace std;

long long a[1000005];

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;

    long long cnt = 0;
    cin>>s;
    for(int i = 0; i < s.size(); i++) {
        a[cnt] = -1;
        if(s[i] == '0') {
            a[cnt] = 0;
            cnt++;
        }else if(s[i] == '1') {
            a[cnt] = 1;
            cnt++;
        }else if(s[i] == '2') {
            a[cnt] = 2;
            cnt++;
        }else if(s[i] == '3') {
            a[cnt] = 3;
            cnt++;
        }else if(s[i] == '4') {
            a[cnt] = 4;
            cnt++;
        }else if(s[i] == '5') {
            a[cnt] = 5;
            cnt++;
        }else if(s[i] == '6') {
            a[cnt] = 6;
            cnt++;
        }else if(s[i] == '7') {
            a[cnt] = 7;
            cnt++;
        }else if(s[i] == '8') {
            a[cnt] = 8;
            cnt++;
        }else if(s[i] == '9') {
            a[cnt] = 9;
            cnt++;
        }
    }
    sort(a, a + cnt);
    if(a[cnt - 1] == 0) {
        cout<<0;
        return 0;
    }
    for(int i = cnt-1; i >= 0; i--) {
        cout<<a[i];
    }
    return 0;
}
