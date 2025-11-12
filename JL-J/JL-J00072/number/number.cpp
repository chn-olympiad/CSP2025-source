#include<bits/stdc++.h>
using namespace std;
string s;
string ans;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]<='9'&&s[i]>='0'){
            ans+=s[i];
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    cout<<ans;
    return 0;
}
