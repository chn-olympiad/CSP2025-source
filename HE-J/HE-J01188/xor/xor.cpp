#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10000000],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	else if(k==0){
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
			else if(a[i]==1&&a[i+1]==1)
			{
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
	return 0;
}
