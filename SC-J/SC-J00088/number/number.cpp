#include <bits/stdc++.h>
using namespace std;
string s,ans;
int cnt[10];
bool flag;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.length();i++) cnt[s[i]-'0']++;
    for(int i = 9;i >= 0;i--)
        if(i || !i && flag){
            flag = 1;
            while(cnt[i]--) ans += '0' + i;
        }else ans += '0';
    cout << ans;
    return 0;
}
// fc 文件1 文件2
