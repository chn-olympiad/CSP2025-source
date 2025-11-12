#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,ans;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            ans+=s[i];
    }
    sort(ans.begin(),ans.end(),cmp);
    if(ans[0]=='0')
        cout<<0;
    else
        cout<<ans;
    return 0;
}
