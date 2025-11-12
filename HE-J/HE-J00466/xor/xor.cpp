#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500009];
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
	int l=1,r=1;
	while(1)
	{
		int cnt=a[l];
		while(cnt!=k&&r<=n)
		{
			r++;
			cnt=(cnt^a[r]);
		}
		if(cnt==k)
		{
			ans++;
			l=r+1;
			r++;
			cnt=0;
		}
		if(r>n)
		{
			cout<<ans;
			return 0;
		}
	}
	//CCF are sb!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//fuck ccf's mother£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
	//ccf don't have 78 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
