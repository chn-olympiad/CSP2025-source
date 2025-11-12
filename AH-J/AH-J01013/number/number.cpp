#include<bits/stdc++.h>
using namespace std;
string s,a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++) if(s[i]<='9'&&s[i]>='0') a+=s[i];
    sort(a.begin(),a.end());
    for(long long i=a.size()-1;i>=0;i--) cout<<a[i];
    return 0;
}
