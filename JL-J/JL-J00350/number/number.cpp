#include<bits/stdc++.h>
using namespace std;
string s;
const int maxn = 1e6 + 10;
int a[maxn];
int n;
int k;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    n = s.size() - 1;
    for(int i = 0 ; i <= n ; i ++ ) {
        if(s[i] >= '0' && s[i] <= '9') a[++ k] = s[i] - '0';
    }
    sort(a + 1 , a + 1 + k , cmp);
    for(int i = 1 ; i <= k ; i ++) cout << a[i];
    return 0;
}