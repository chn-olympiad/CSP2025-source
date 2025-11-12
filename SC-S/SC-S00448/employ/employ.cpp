#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[505];
int c[505];
int ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char st;
		st=getchar();
		s[i]=st-'0';
		if(s[i]==1)
		{
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cout<<ans;
	return 0;
}