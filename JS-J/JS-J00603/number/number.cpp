#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[11],l;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    sort(s.begin(),s.end());
    while(s[++l]<='9'&&l<s.size());
    s=s.substr(0,l);
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}
