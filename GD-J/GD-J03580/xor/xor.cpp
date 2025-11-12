#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
bool flag[N];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		flag[i]=true;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int p=0;
			bool f=true;
			for(int l=i;l<=j;l++)
			{	
				if(flag[l]==true)
				{
					p=p^a[l];
				}
				else
				{
					f=false;
					break;
				}
			}
			if(p==k&&f==true)
			{
				for(int l=i;l<=j;l++)
				{
					flag[l]=false;
				}
				ans++;
				break;
			}
		}
	}
	cout<<ans;
return 0;
}
