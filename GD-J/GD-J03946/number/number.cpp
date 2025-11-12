#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	char b[3000000];
	int c=1;
	cin>>a;
	int l=a.size();
	for(int i=0;i<l;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[c]=a[i];
			c++;
		}
	}
	c--;
	sort(b+1,b+c+1);
	for(int i=c;i>=1;i--)
	{
		cout<<b[i];
	}
	return 0;
}
