#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    string num="";
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) num+=s[i];
    }
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    cout<<num;
    return 0;
}
//file memory long long
