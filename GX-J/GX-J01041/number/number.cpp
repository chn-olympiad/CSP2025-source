#include<iostream>
#include<cstring>
using namespace std;
char a[10001],b[10001];
string s;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
long long  i,j,n,m;
cin>>s;
for(i=0;i<=10001;++i)
a[i]=s[i];
n=strlen(a);
i=0;j=0;
for(i=0;i<=n;++i)
    b[i]=0;
while(i<=n)
{
    if(a[i]>=48&&a[i]<=57){j+=1;b[j]=a[i];}
    ++i;
}
for(i=0;i<=n;++i)
    for(j=0;j<=n;++j)
{
    if(b[i]<b[i+1]){swap(b[i],b[i+1]);}
}
for(i=1;i<=n;++i)
if(b[i]!=0)cout<<b[i];
cout<<endl;
return 0;
}
