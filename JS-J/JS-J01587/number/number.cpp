#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005],cnt=1;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            continue;
        else
        {
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt-1;i++)
        cout<<a[i];
    return 0;
}
