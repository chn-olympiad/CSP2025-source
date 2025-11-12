#include<bits/stdc++.h>
using namespace std;

long long a[100005];

bool cmp(long long x, long long y){
    return x>y;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    string ans = "";
    for(long long i = 0;i<s.size();i++){
        if(isdigit(s[i])){
            ans+=s[i];
        }
    }
    long long n = ans.size();
    for(long long i = 0;i<ans.size();i++){
        a[i] = ans[i]-'0';
    }
    sort(a, a+n, cmp);
    for(long long i = 0;i<n;i++){
        cout << a[i];
    }
    return 0;
}
