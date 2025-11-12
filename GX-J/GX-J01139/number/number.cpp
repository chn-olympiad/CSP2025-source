#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
int maxn,maxx,b[N],sum[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    int n = s.size();
    if (s.size() == 1){
        cout << s;
    }else if (s.size() == 2){
        if (s[0] > s[1]){
            cout <<s;
        }
    }
    return 0;
}
