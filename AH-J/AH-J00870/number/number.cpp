#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
int s=a.size();
for(int q=1;q<s;++q)
{
	char z;
	if(a[q]<'a')
	{
		for(int w=0;w<q;++w)
	{
	if(a[w]<a[q])
	{
		z=a[w];
		a[w]=a[q];
		a[q]=z;
	}
	}
}		
}
for(int q=0;q<s;++q)
{
if(a[q]<'a')
{
	cout<<a[q];
}
}
	return 0;
}


