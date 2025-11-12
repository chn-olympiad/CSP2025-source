#include<bits/stdc++.h>
using namespace std;
string s,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans.insert(lower_bound(ans.begin(),ans.end(),s[i]),1,s[i]);
        }
    }
    if(ans[ans.size()-1]=='0'){
        cout<<0<<"\n";
        return 0;
    }else{
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i];
        }
    }
    cout<<"\n";
    return 0;
}