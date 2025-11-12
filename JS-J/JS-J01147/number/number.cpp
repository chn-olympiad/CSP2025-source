#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
string s;
int a[maxn];
int cnt;
bool cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int len = s.size();
    for(int i = 0; i < len; i++){
        if(s[i] >= '0' && s[i] <= '9')
            a[++cnt] = s[i] - '0';
    }
    sort(a + 1, a + cnt + 1, cmp);
    for(int i = 1; i <= cnt; i++)
        printf("%d", a[i]);
    cout<<endl;
    return 0;
}