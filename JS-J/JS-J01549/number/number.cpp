#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>v;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]>='0'&&s[i]<='9'){
            v.push_back(s[i]-'0');
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();++i) cout<<v[i];
    return 0;
}
//think more of DP
//read problems carefully
//look out the special stds
