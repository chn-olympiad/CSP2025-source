#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int top = 1;
string res = "";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.size();i ++ ){
        if(iswdigit(s[i])){
            a[top ++] = (s[i] - '0');
        }
    }
    sort(a + 1,a + top);
    for(int i = top - 1;i >= 1;i -- ){
        res += (a[i] + '0');
    }
    cout << res << endl;
   return 0;
}
