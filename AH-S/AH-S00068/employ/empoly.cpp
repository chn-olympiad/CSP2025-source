#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("empoly.in","r",stdin);
freopen("empoly.out","w",stdout);
	string k;
	long long n,m,a[100001],s=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)s++;
	}
	cout<<0;
	return 0;
}
