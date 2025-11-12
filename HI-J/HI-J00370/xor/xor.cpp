#include <bits/stdc++.h>
using namespace std;
int n,k,a[500500];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int i=1;
	if(n<=2&&k==0)cout<<1;
	else 
	{
		int ans=0;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]!=a[i+1])i++,ans++;
			}
		}
		else 
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==a[i+1])i++,ans++;
			}
		}
		cout<<ans;
	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//不同为1，相同为0 
// 这啥呀 …… 
