#include<bits/stdc++.h>
using namespace std;
const long long N=pow(10,6)+9;
int b[N],z=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int c=a.length();
	for(int i=0;i<c;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[z]=a[i]-'0';
			z++;
		}
	}
	sort(b,b+z);
	for(int i=z-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
