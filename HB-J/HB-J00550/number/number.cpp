#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> num;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num.push_back(s[i]-'0');
        }
    }
    sort(num.begin(),num.end(),greater<int>());
    for(int i=0;i<num.size();i++){
        cout<<num[i];
    }
    return 0;
}
