#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll num,a[1000010];char ch;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ch = getchar();
    while(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z'){
        if(ch >= '0' && ch <= '9') a[++num] = ch - '0';
        ch = getchar();
    }
    sort(a + 1,a + num + 1);
    if(a[num] == 0){cout << "0\n";return 0;}
    for(int i = num;i >= 1;i--) cout << a[i];
    return 0;
}
