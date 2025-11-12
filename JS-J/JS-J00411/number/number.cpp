#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <functional>
#include <cstdio>
using namespace std;

string s;
int num[1000005],tot;

int main (){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (int i=0;i<s.size();i++){
        if (isdigit(s[i])){
            num[++tot]=s[i]-'0';
        }
    }
    sort(num+1,num+tot+1,greater<int>());
    for (int i=1;i<=tot;i++){
        cout << num[i];
    }
    cout << endl;
    return 0;
}
//rp++