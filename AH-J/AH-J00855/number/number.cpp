#include<bits/stdc++.h>
using namespace std;
vector <int> ans;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            int temp=s[i]-'0';
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    int len=0;
    while(len<ans.size()-1&&ans[len]==0){
        len++;
    }
    for(int i=len;i<ans.size();i++){
        cout<<ans[i];
    }
    return 0;
}
