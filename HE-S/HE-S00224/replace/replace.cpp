#include<bits/stdc++.h>
using namespace std;
string a[500005],b[500005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		cnt++;
	}
	ans=max(ans,cnt);
	int anh=0;
	for(int i=1;i<=m;i++)
	{
		string x,y;
		cin>>x>>y;
		for(int i=1;i<=ans;i++)
		{
			if(x==a[i]||x==b[i])
			{ 
				anh++;
			}
			if(y==a[i]||y==b[i])
			{ 
				anh++;
			}
		}
		if(anh%2==1)
		{
			cout<<anh<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
