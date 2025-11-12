#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,a="";
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(LL i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a+=s[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    cout<<a;
    return 0;
}
