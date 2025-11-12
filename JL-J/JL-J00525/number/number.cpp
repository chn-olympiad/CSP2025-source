#include<bits/stdc++.h>
using namespace std;
#define N 10000005
char a[N];
long long len,q,b[N];
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
len=strlen(a);
for(long long i=0;i<len;i++)
{
	if(a[i]>='0'&&a[i]<='9')
	{
	b[q++]=(a[i]-'0');
	}
}
sort(b,b+q);
if(b[q-1]==0)cout<<'0';
else 
{
	for(int i=q-1;i>=0;i--)printf("%lld",b[i]);
}
cout<<endl;
return 0;
}
