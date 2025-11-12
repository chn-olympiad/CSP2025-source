#include<iostream>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,l=1;
	cin>>n>>m;
	if(n==m)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		l*=i;
	}
	cout<<l;
	return 0;
}
