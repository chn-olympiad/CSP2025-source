#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    vector<int>v;
    for(int i = 0;i <= s.length(); i++){
        if('0' <= s[i]&&s[i] <= '9') v.push_back(s[i] - '0');
    }
    sort(v.begin(),v.end(),cmp);
    int siz = v.size();
    for(int i = 0;i <= siz - 1; i++){
        cout<<v[i];
    }
    return 0;
}
