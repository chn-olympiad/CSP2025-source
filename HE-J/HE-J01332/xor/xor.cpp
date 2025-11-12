#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1];
	int ans[((n*(n-1))/2)];
	int count=1,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=((n*(n-1))/2);i++)
	{
		ans[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int Elem=i;Elem<=j;Elem++)
			{
				ans[count]=ans[count]^a[Elem];
			}
			count++;
		}
	}
	for(int i=1;i<=count;i++)
	{
		if(ans[i]==k) sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
