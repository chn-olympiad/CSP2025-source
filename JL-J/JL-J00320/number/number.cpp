#include<bits/stdc++.h>
using namespace std;
int cnt[258];string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)cnt[s[i]]++;
    for(int i='9';i>='0';i--)cout<<string(cnt[i],i);
}
