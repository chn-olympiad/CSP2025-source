#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int N = 1e6+10;
int a[N], tot;
bool cmp(int a, int b){return a > b;}
int main(){
    freopen("number4.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] >= '0' && s[i] <= '9') a[++tot] = (int)s[i]-'0';
    sort(a+1, a+tot+1, cmp);
    for(int i = 1; i <= tot; ++i) cout << a[i];
    return 0;
}
