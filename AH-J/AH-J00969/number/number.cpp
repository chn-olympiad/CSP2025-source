#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++) if(isdigit(s[i])) x+=s[i];
    sort(x.begin(),x.end());
    reverse(x.begin(),x.end());
    cout<<x;
    return 0;
}
