#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 15;
int a[maxn];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int len = s.size();
    int n = 0;
    for(int i = 0;i < len;i ++)
    {
        if(isdigit(s[i])){
            n ++;
            a[n] = s[i] - '0';
        }
    }
    sort(a + 1, a + 1 + n);
    for(int i = n;i >= 1;i --)
    {
        cout << a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
