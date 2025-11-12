//WTX
#include <iostream>
#include <cstring>
using namespace std;
int cu[10],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for (int i = 0;i<s.size();i++){
        if (s[i]>='0'&&s[i]<='9'){
            cu[s[i]-'0']++,cnt++;
        }
    }
    for (int i = 9;i>=0;i--){
        for (int j = 1;j<=cu[i];j++){
            cout << i;
        }
    }
    return 0;
}
/**
//freopen
itn
lnog logn
Never Gonna Give U Up
Praise CCF!
RP+=2147483647

2427FOREVER
2026FOREVER
0817FOREVER
0235FOREVER
PRAISE CCF FOREVER

AFO FOREVER

LMCC RP += INT_MAX

Ci Sheng Wu Hui Ru OI
Lai Shi Hai Zuo OI Ren


**/
