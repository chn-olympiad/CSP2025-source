#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
vector<int> a;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&& s[i]>='0'){
            a.push_back(s[i]-'0');
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<a.size();i++){
        cout<<a[i];
    }
    return 0;
}