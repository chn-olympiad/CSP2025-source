#include<bits/stdc++.h>
using namespace std;
int cnt[128];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)cnt[s[i]]++;
    for(int i=9;i>=0;i--)for(int j=1;j<=cnt[i+'0'];j++)cout<<i;
}
