#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 1;i < s.size()-1;i++){
        if(s[i] >= '1' && s[i] <= '9')a[i] = s[i] - 32;
    }//sort(a,a+s.size());
    for(int i = 0;i <= s.size-1;i++)cout << a[i];
    return 0;
}
