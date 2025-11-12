#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s,ans,ans1;
    cin >> s;
    ans1 = "";
    ans = "";

    for (int i = 0; i < s.size(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            ans1 += s[i];
        }
    }

    for (int i = 9; i >= 0; i--){
        for (int j = 0; j < ans1.size(); j++){
            if (ans1[j] == i+'0') ans += ans1[j];
        }
    }

    cout << ans;

    return 0;
}
