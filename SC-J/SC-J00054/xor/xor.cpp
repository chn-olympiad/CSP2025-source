#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
const int N=10000;
//25骗分：）
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(m==0)
		{
			if(a[i]==1&&a[i-1]==1)
			{
				ans++;
				i++;
			}
		}
		else
		{
			if(a[i]!=a[i-1])
			{
				ans++;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}