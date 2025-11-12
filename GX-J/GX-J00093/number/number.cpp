#include <bits/stdc++.h>
using namespace std;
string s; int a[1000005];int m=1;
bool isempty(){
    if (m == 1){
        return true;
    }
    for (int i = 1;i <= m;i++){
        if (a[i] != -1){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("number.in", "r", stdin);freopen("number.out", "w", stdout);
    memset(a, -1 ,sizeof(a));
    cin >> s;
    for (int i = 0;i < s.length();i++){
        if ((s[i]-'0' >= 0) && (s[i]-'0' <= 9)){
            a[m++]=s[i]-'0';
        }
    }
    string res;
    while (!(isempty())){
        int maxa = -1, p=0;
        for (int i = 1;i <= m;i++){
            if (a[i] > maxa){
                maxa = a[i];
                p = i;
            }
        }
        a[p] = -1;
        char num = maxa + '0';
        res += num;
    }
    cout << res;
    return 0;
}
