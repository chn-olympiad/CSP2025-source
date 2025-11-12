#include<bits/stdc++.h>
using namespace std;
int a[1000000],sum,z;
string b;
int c(int x,int y)
{
	return x>y;
	
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	int l=b.length();
	for(int i=0;i<l;i++)
	{
		if(b[i]>='0'&&b[i]<='9')
		{
			a[z]=b[i]-'0';
			z++;
		}
	}
	sort(a,a+z,c);
	for(int i=0;i<z;i++)
	{
		cout<<a[i];
	}
	//½â×¢ÊÍ 
	return 0;
}
