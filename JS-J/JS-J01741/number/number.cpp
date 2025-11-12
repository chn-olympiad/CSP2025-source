#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    vector<int>a;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            a.push_back(s[i]-'0');
        }
    }
    sort(a.begin(),a.end());
    for(int i=a.size()-1;i>=0;i--)cout<<a[i];
    return 0;
}

