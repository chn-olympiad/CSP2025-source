#include<bits/stdc++.h>
using namespace std;
long long b[1000010],zong=0;
int A(int a,int o)
{
	return a>o;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	
	for(int z=0;z<a.size();z++)
	{
		if(a[z]>='0'&&a[z]<='9')
		{
			zong++;
			b[zong]=a[z]-48;
		}
	}
	sort(b+1,b+1+zong,A);
	for(int z=1;z<=zong;z++)
	{
		cout<<b[z];
	}
	return 0;
}
