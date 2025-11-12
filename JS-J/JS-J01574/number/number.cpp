#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0') a[++cnt]=0;
        if(s[i]=='1') a[++cnt]=1;
        if(s[i]=='2') a[++cnt]=2;
        if(s[i]=='3') a[++cnt]=3;
        if(s[i]=='4') a[++cnt]=4;
        if(s[i]=='5') a[++cnt]=5;
        if(s[i]=='6') a[++cnt]=6;
        if(s[i]=='7') a[++cnt]=7;
        if(s[i]=='8') a[++cnt]=8;
        if(s[i]=='9') a[++cnt]=9;
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--)
    {
        cout<<a[i];
    }
    cout<<'\n';
    return 0;
}
