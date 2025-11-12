#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v;
bool cmp(int a,int b){
    return a>b;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            v.push_back(s[i]-48);
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++) cout<<v[i];
    return 0;
}
