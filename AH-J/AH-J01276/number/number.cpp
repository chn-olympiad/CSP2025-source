#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int b[205];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        b[s[i]]++;
    }
    for(int i='9';i>='0';i--){
        for(int j=1;j<=b[i];j++){
            cout<<(char)i;
        }
    }
    return 0;
}
