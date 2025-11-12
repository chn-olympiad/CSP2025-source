#include <bits/stdc++.h>
using namespace std;
vector<int> num;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i]))
            num.push_back(s[i]-'0');
    }
    sort(num.begin(),num.end(),greater<int>());
    for(int i=0;i<num.size();i++)
        cout<<num[i];
    return 0;
}
