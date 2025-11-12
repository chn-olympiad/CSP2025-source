#include <bits/stdc++.h>
using namespace std;
char a[1000001];
int cnt = 0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c;
    while(cin >> c){
        if(c >= '0' && c <= '9'){
            a[++cnt] = c;
        }
    }
    sort(a+1,a+cnt+1);
    for(int i = cnt;i >= 1;i --){
        cout << a[i];
    }
    return 0;
}