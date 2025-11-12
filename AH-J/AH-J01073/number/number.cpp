#include<bits/stdc++.h>
using namespace std;
string ss;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) ss+=s[i];
    }
    cout<<ss;
    return 0;
}
