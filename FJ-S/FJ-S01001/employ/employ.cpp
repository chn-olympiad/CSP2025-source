#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,ans=1;
	string s;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans*=i;
	}	
	cout<<ans;
	return 0;
}
