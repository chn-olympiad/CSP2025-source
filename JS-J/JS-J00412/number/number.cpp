#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,res;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(isdigit(s[i])) res+=s[i];
    sort(res.begin(),res.end());
    reverse(res.begin(),res.end());
    cout<<res<<"\n";
    return 0;
}