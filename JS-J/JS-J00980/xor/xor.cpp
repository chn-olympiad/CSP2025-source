#include <bits/stdc++.h>
using namespace std;
string zh210(int a){
    vector <char> as;
    string s;
    while (a != 0){
        as.push_back(char(a % 2 + 48));
        a = a / 2;
    }
    for (int i = as.size() - 1;i >= 0;i--){
        s += as[i];
    }
    return s;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    vector <long long> v;
    vector <long long> f;
    vector <string> s;
    cin >> n >> k;
    bool ff = true,fff = true;
    int s1,s0;
    for (long long i = 0;i < n;i++){
        int tf;
        cin >> tf;
        v.push_back(tf);
        if (v[i] != 1){
            ff = false;
        }
        if (v[i] != 1 || v[i] != 0){
            fff = false;
        }
        if (v[i] == 1){
            s1++;
        }
        if (v[i] == 0){
            s0++;
        }
    }
    if (ff){
        cout << n;
    }
    else if (fff){
        if (k == 0){
            cout << n - s1;
        }
        else{
            if (s0 % 2 == 0){
                cout << s0 / 2 + s1;
            }
            else{
                cout << s0 / 2 + s1 - 1;
            }
        }
    }
    else{
        if (k == 0){
            cout << s0;
        }
        else if (n % k == 0){
            cout << n/k;
        }
        else{
            cout << n / k + 1;
        }
    }

    return 0;
}
