#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> ans;
    for (int i=0;i < s;.size(); ++i){
        if(isdigit(s[i])){
            ans.push_back(s[i] - 0);
        }
    }
sort(ans.begin(),ans.end())
for(int i =ans.size() - 1; i>=0 ; -- i){
    cout<<ans[i]
}
    return 0;
}
