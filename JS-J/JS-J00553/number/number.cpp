#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    string x;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            x=x+s[i];
        }
    }
    sort(x.begin(),x.end(),greater<int>());
    cout<<x;
    return 0;
}
