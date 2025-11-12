#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int num=a[j]^a[i];
			if(a[i]==k)
			{
				ans++;
				break;
			}
			else if(num==k)
			{
				ans++;
				i=j;
				break;
			}
			else
			{
				num^=a[j+1];
			}
		}	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
