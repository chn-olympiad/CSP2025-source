#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
string s;
int a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int t=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9') a[++t]=s[i]-'0';
    }
    sort(a+1,a+1+t,cmp);
    for(int i=1;i<=t;i++)
        cout<<a[i];
    return 0;
}
