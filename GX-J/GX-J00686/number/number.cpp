#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool dx(int a,int b)
{
    return a>b;
}
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
long long e=0;
cin>>s;
for(long long i=0;i<s.size();i++)
{
    if(s[i]>='0'&&s[i]<='9')
    {
        e++;
        a[e]=s[i]-'0';
    }
}
sort(a+1,a+1+e,dx);
for(long long i=1;i<=e;i++)
{
    cout<<a[i];
}
return 0;
}
