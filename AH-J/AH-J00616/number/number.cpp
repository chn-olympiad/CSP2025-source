#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int i,x,m=0;
	cin>>n;
	x=n.size()-1;
	for(i=0;i<=x;i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			m++;
			a[m]=n[i]-'0';
		}
	}
	sort(a+1,a+m+1);
	for(i=m;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
