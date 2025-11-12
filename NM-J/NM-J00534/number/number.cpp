#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long a[10000],ans = 0;
    string s,s1 = "";
    cin >> s;
    for (int i = 0;i < s.length();i++){
        if (s[i] <= 'z' && s[i] >= 'a') continue;
        else{
            a[ans] = s[i] - '0';
            ans++;
        }
    }
    for (int j = 1;j <= ans;j++){
        for (int i = 1;i < ans;i++){
            if (a[i] > a[i - 1]){
                int t = a[i - 1];
                a[i - 1] = a[i];
                a[i] = t;
            }
        }
    }
    long long v = 0;
    for (int i = 0;i < ans;i++) v += a[i]*pow(10,ans-i-1);
    cout << v;
    return 0;
}
