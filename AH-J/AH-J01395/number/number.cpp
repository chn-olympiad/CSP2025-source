#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string s;
    cin>>s;
    string x="";
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')x+=s[i];
    }sort(x.begin(),x.end());
    bool f=0;
    for(int i=x.size()-1;i>=0;i--){
        if(x[i]!='0')f=1;
        if(f)cout<<x[i];
    }if(!f)cout<<0;
    return 0;
}
