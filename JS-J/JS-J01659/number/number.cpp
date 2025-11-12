#include <bits/stdc++.h>
using namespace std;

string s;
int a[10], flg=true;

bool cmp(int a, int b){
    return a>b;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin>>s;
    for (int i=0;i<s.length();i++){
        if ('0'<=s[i] && '9'>=s[i]){
            a[s[i]-'0']++;
        }
    }
    for (int i=9;i>=0;i--){
        if (i==0 && flg){
            cout<<0; break;
        }
        for (int j=0;j<a[i];j++) {
            cout<<i; flg=false;
        }
    }
    cout<<endl;
    return 0;
}

