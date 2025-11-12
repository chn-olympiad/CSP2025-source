#include<bits/stdc++.h>
using namespace std;
long long a[50010];
long long n,k,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k<=1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==k)
				ans++;
		}
		if(ans!=0)
			cout<<ans;
		else
			cout<<n/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 