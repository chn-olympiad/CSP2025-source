#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],cnt=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=48&&s[i]<=57) a[++cnt]=s[i]-'0';
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--)
    {
        printf("%d",a[i]);
    }
    return 0;
}
