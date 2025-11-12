#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    for(int i=0;i<s.size();i++) a[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        while(a[i]--) cout<<i;
    return 0;
}
