#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    int len=s.length();
    for(int i=1;i<=len;i++) a[i]=s[i-1]-'0';
    sort(a+1,a+len+1);
    for(int i=len;i>=1;i--) if(a[i]<=9) cout<<a[i];
    return 0;
}