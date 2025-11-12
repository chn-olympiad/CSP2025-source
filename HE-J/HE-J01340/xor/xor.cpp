#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500100],ans,x,maxn=0;
bool f=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int c=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			maxn++;
		}
	}
	for(int t=1;t<=n;t++)
	{
		ans=0;
		for(int i=t;i<=n;i++)
		{
			x=a[i];
			f=0;
			if(a[i]==k)
			{
				ans++;
				continue;
			}
			for(int j=i+1;j<=n;j++)
			{
				x=x^a[j];
				if(x==k)
				{
					i=j+1;
					f=1;
					break;
				}
			}
			if(f==1)
			{
				ans++;
			}
		}
		maxn=max(ans,maxn);
	}
	cout<<maxn;
	return 0;
}
