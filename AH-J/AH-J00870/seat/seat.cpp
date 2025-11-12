#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int a,s,d[a*s],D[a*s];
cin>>a>>s;
for(int q=0;q<s*a;++q)
{
	cin>>d[q];
}
int c,b=d[0];
for(int q=0;q<a*s;++q)
{int z,x;
for(int w=0;w<a*s;++w)
{
z=0;
if(z<d[w])
{
	a=d[w];x=w;
}
}
D[q]=z;d[x]=-1;
}
for(int q=0;q<a*s;++q)
{
if(D[q]==b)
{
	c=q+1;break;
}
}
if(c%a==0)
{
if(c/a%2==0)
{
	cout<<c/a<<' '<<1;
}
		else
{
	cout<<c/a<<' '<<a;
}
}
else
{
	if((c/a+1)%2==0)
{
	cout<<c/a+1<<' '<<a-c%a+1;
}
else
{
	cout<<c/a+1<<' '<<c%a;
}
}
	return 0;
}
