#include <bits/stdc++.h>
using namespace std;
string s;
int num[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            num[s[i]-'0']++;
        }
    }
    string ans;
    for(int i = 9; i >= 0; i--)
    {
        while(num[i] > 0)
        {
            ans += (i+'0');
            num[i]--;
        }
    }
    cout << ans;
    return 0;
}