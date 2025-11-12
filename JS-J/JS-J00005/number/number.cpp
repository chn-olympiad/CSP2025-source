#include<bits/stdc++.h>
using namespace std;

int cnt[20];
string s;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s;
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<s.size();i++)
        if(s[i]>='0' && s[i]<='9') cnt[s[i]-48]++;
    for(int i=9;i>=0;i--) 
        for(int j=1;j<=cnt[i];j++) cout<<i;
    cout<<'\n';
    return 0;
}