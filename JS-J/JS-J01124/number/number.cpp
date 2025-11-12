#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 110;
int cnt[N];

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int lens = s.length();
    for(int i = 0;i < lens;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            cnt[s[i] - '0']++;
        }
    }
    string t;
    for(int i = 9;i >= 0;i--){
        int ret = cnt[i];
        while(ret > 0){
            t += i + '0';
            ret--;
        }
    }
    cout << t << "\n";
    return 0;
}
