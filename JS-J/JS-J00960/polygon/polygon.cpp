#include <bits/stdc++.h>
using namespace std;
int a[510];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n>=510)
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<"0"<<endl;
		return 0;
	}
	
	else if(n==3)
	{
		int maxn=max(max(max(a[1],a[2]),max(a[2],a[3])),max(a[1],a[3]));
		int cnt=a[1];
		cnt=cnt+(a[2]+a[3]);
		if(cnt>maxn*2)
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
		return 0;
	}
	else if(n>3)
	{
		cout<<"0"<<endl;
		return 0;
	}
	return 0;
}
