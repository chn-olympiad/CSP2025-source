#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char a[n+1];
	int c[n+1],t=0;
	bool f=0;
	unsigned long long jc[m+1]={1};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			f=1;
			t++;
		}	
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		jc[i]=i*jc[i-1];
	}
	if(n-t<m)
		cout<<0;
	if(f==0)
		cout<<jc[m]%998244353;
	
	return 0;
 } 
