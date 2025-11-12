#include<bits/stdc++.h> 
using namespace std;
#define inf 100002
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,k,ans=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n; 
		for(k=1;k<=n;k++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			ans+=max(x,max(y,z));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
