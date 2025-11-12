#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,h[1000005];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(ll i = 0;i < s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            h[++t] = s[i] - '0';
        }
    }
    sort(h + 1,h + 1 + t);
    if(h[t] == 0)
        return 0;
    for(ll i = t;i >= 1;i--){
        cout << h[i];
    }
    cout <<endl;
    return 0;
}
