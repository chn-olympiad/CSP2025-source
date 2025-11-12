#include<bits/stdc++.h>
using namespace std;
int n,m,num;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a,b;
	cin>>a;
	for(int i=2;i<=n*m;i++)
	{
		cin>>b;
		if(b>a)
		{
			num++;
		}
	}
	int k=(num+n)/n;
	cout<<k<<" ";
	int o=(k-1)*n;
	num++;
	if(k%2==0)
	{
		cout<<n-(num-o)+1;
	}
	else
	{
		cout<<num-o;
	}
	return 0;
}