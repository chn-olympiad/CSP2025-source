#include<bits/stdc++.h>
#define LL long long
using namespace std;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    LL x = 0;
    for(LL i = 0;i < sizeof(s);i++){
        if('0' <= s[i] && '9' >= s[i]){
            a[x] = s[i] - '0';
            x++;
        }
    }
    sort(a,a+x);
    for(LL i = x - 1;i >= 0;i--){
        cout << a[i];
    }
    return 0;
}