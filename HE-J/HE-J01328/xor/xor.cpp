#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],sum,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			for(int i=l;i<=r;i++)
			{
				if(i==l)
				{
					sum=a[i];
				}
				else
				{
					sum=sum^a[i];
				}
			}
			if(sum==k)
			{
				ans++;
				l=r;
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
