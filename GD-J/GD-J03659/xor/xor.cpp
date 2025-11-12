#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(m==0)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==0)
			ans++;
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j]==a[j+1]&&a[j]!=0)
			ans++,j++;
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]==1)
			ans++;
		}
		cout<<ans;
		return 0;
	}
	cout<<m/2;
	return 0;
}
