#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]<='9'&&s[i]>='0')v.push_back(s[i]-'0');
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)cout<<v[i];
    return 0;
}
