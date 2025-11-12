#include<bits/stdc++.h>
using namespace std;
int n,ans1;
int a[10000];
int ans[200002];
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//ans[1]=1;
	for(int i=1;i<=n-2;i++)
	{
		ans1+=ans[i-1]+i;
		for(int j=1;j<i;j++)
		{
			ans[i]=ans[j];
		}
		ans[i]+=ans1;
		cout<<ans[i]<<" ";
	}
	cout<<ans[n-2]<<endl;
	return 0;
}
