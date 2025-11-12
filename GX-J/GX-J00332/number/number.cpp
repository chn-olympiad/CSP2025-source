#include<iostream>
#include<cstring>
using namespace std;
long long a[1001];
char s[1001];
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
long long i,j,n,p;
cin>>s;
n=strlen(s);
//cout<<s<<n;
p=0;
for(i=0;i<=n;++i)
{
if(s[i]>='0'&&s[i]<='9') {p++;a[p]=s[i]-48;}}
for(i=1;i<=p;++i)
for(j=1;j<=p;++j)
if(a[i]>a[j]) swap(a[i],a[j]);
for(i=1;i<=p;++i)
cout<<a[i];
return 0;
}
