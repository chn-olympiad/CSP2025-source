#include<bits/stdc++.h>
using namespace std;

string s;
vector<char> ans;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans.push_back(s[i]);
        }
    }
    sort(ans.begin(),ans.end(),greater<char>());
    for(auto x:ans){
        printf("%c",x);
    }
}
