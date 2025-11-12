#include <bits/stdc++.h>
#define int long long
#define I_AK_CSP return 0
#define fr(k,n) for(int i=k;i <= (n);i ++)

using namespace std;

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int b[15]={};
    fr(0,s.length()-1){
        if (isdigit(s[i])){
            b[s[i]-'0']++;
        }
    }
    for (int i = 9;i >= 0;i --){
        for (int j = 1;j <= b[i];j ++)cout << i;
    }
    I_AK_CSP;
}
