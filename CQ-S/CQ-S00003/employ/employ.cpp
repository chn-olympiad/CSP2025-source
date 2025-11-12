#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string sum;
int a[50005];
int main()
{
	cin>>n>>m;
	cin>>sum;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=lenth(sum);i++)
	{
		s[i]=sum[i-1];
	}
	for(int i=1;i<=n*n;i++)
	{
		if(a[i]<=2)
		{
			ans+=1;
			continue;
		}
		else
		{
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
