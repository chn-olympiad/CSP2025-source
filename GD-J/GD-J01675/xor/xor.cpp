#include<bits/stdc++.h>
using namespace std;
int n,K,a[500005],s[305];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[a[i]]++;
	bool flag1=true;
	for(int i=0;i<=255;i++)
		if(s[i]>0&&i!=1&&i!=0)
		{
			flag1=false;
			break;
		}
	if(flag1)
	{
		if(s[0]==0)
		{
			if(K==0)cout<<n/2;
			else cout<<n;
		}
		else
		{
			if(K==0)cout<<s[1]/2;
			else cout<<s[1];
		}
		return 0;
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int bp=0;
			for(int j=i;j<=n;j++)
			{
				int p=0;
				for(int k=i;k<=j;k++)
				{
					p^=a[k];
				}
				if(p==K)
				{
					bp=j;
					break;
				}
			}
			if(bp!=0)
			{
				ans++;
				i=bp;
			}
		}
		cout<<ans;
	}
	return 0;
}
