#include<bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define rep(a) for(int i = 0;i < a;i++)
#define per(a) for(int i = (a) - 1;i >= 0;i--)
int a[80];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    rep(sz(s)) a[s[i]-'0'] ++;
    per(10){
        for (int j = 0;j < a[i];j++) cout << i;
    }
    return 0;
}
