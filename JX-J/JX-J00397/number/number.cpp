#include<bits/stdc++.h>
using namespace std;
int s[25],n,m;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
m=a.size();
for(int i=0;i<m;i++)
{

if(a[i]>='0'&&a[i]<='9')
{
s[n]=a[i]-'0';
n++;
}
}
sort(s,s+n);
for(int i=n-1;i>=0;i--)
{
cout<<s[i];
}
return 0;
}
