#include<bits/stdc++.h>
using namespace std;
long long t,n,a[10086][10086],ans=0;
int main()
{
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				ans=max(ans,a[i][j]);

			}
		cout<<ans<<endl;
		ans=0;
	}

	return 0;
 }
