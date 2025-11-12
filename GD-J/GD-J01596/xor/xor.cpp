#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main()
{
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0)
	{
		for(int i=1;i<=n;i++)if(!a[i])ans++;
		else if(a[i]==a[i-1])ans++;
		cout<<ans;
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)if(a[i]==1)ans++;
		cout<<ans;
		return 0;
	}
}

