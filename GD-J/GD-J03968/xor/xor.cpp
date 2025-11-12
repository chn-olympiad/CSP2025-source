#include<bits/stdc++.h>
using namespace std;
int n,k,a[100010],num[100010];
int maxn=-1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2&&k==0)
	{
		if(n==1)
		{
			if(a[1]==0)
			{
				cout<<1;
			}
			else cout<<0;
		}
		else if(n==2)
		{
			if(a[1]==0&&a[2]==0)cout<<2;
			else if(a[1]==a[2])
			{
				cout<<1;
			}
			else 
			{
				cout<<0;
			}
		}
	}
//	else if(n>2&&n<=10)
//	{
//		sum[1]=a[1];
//		for(int i=2;i<=n;i++)
//		{
//			num[i]=num[i-1]^a[i];
//		}
//		
//	}
	return 0;
}
