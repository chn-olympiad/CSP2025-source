#include <bits/stdc++.h>
using namespace std;
int ee(string a)
{
int max=0,all=0,s=a.size();
for(int q=0;q<s;++q)
{
	if(max<a[q])
	max=a[q];
	all+=a[q];
}
if(all<max*2)
return 0;
else
return 1;
}
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int a,d[a],s=0;
cin>>a;
for(int q=0;q<a;++q)
{
	cin>>d[q];
}
while(1)
{
int z=3;
if(z==a)
{
	++s;break;
}
for(int q=z-1;q<a;++q)
{string x;int v=q;
	while(v>=0)
{
	x[v]=d[v];
	--v;
}
if(ee(x))
{++s;}
}
++z;
}
cout<<s;
	return 0;
}
