#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt;
long long a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--)
    {
        cout<<a[i];
    }
}
