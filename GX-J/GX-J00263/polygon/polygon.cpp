#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,ans1;
	cin>>n;
	int ans[5001];
	for(int i=1;i<=n;i++)
	{
		for(int j;j<=n;j++)
		{
		cin>>ans[i];
		ans1+=ans[i];
		}
	}
	cout<<ans1;
	return 0;
}
