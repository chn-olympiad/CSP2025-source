#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[20];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(isdigit(s[i]))
          a[s[i] - '0']++;
    }
    for(int i = 9;i >= 0;i--){
        while(a[i]--)
            cout << i;
    }
    cout << '\n';
    return 0;
}
