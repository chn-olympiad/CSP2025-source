#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
int a[N],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int j = 0;
    for(int i = 0;i <= s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            cnt++;
            a[j] = s[i] - '0';
            j++;
        }
    }
    sort(a,a + cnt);
    for(int i = cnt - 1;i >= 0;i--){
        cout << a[i];
    }
    return 0;
}
