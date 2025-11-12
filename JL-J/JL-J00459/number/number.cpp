#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
string s;
int a[N];
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>s;
    int cnt=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]-'0'==9||s[i]-'0'==8||s[i]-'0'==7||s[i]-'0'==6||s[i]-'0'==5||s[i]-'0'==4||s[i]-'0'==3||s[i]-'0'==2||s[i]-'0'==1||s[i]-'0'==0)
        {
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    if(a[1]==0) cout<<0;
    else for(int i=1;i<=cnt;i++) cout<<a[i];
    return 0;
}
