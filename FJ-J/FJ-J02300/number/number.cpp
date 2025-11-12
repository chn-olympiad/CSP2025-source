#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	getline(cin,n);
	int a[1000001];
	int num=1;
	int w=n.size();
	for(int i=0;i<w;i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[num]=int(n[i]);
			num++;
		}
	}
	num=num-1;
	for(int i=1;i<=num;i++)
	{
		a[i]=a[i]-48;
	}
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
