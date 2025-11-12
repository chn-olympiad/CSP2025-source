#include<bits/stdc++.h>

using namespace std;
bool cmp(const char& x,const char& y){
    return x >= y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s ;
    string ans;
    for(char c:s){
        if(c >= '0'&&c <= '9'){
            ans.push_back(c);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    cout << ans;
    return 0;
}
