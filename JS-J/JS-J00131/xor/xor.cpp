#include<bits/stdc++.h>
using namespace std;
int n;
int a[500001];
int k;
int ans;
bool b[500001];
int start[500001];
int end[500001];
int pl;
int luck=1;
bool check(int l,int r)
{
	for(int e=l;e<=r;e++)
	{
		int y=a[e];
		for(int f=e+1;f<=r;f++)
		{
			y^=a[f];
			if(y==k&&e!=l)
			{
				return true;
				pl=e-1;
			}
		}
	}
	return false;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		luck=max(luck,a[i]);
		if(a[i]==k)
		{
			ans++;
			b[i]=true;
		}
	}
	if(luck==1)
	{
		if(k==0)
		{
			for(int i=2;i<=n;i++)
			{
				if(a[i]&&a[i-1]&&!b[i]&&!b[i-1])
				{
					ans++;
					b[i]=true;
				}
			}
			cout<<ans;
			return 0;
		}
		if(k==1)
		{
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i])	continue;
		int p=a[i];
		for(int j=i+1;j<=n&&!b[j];j++)
		{
			p^=a[j];
			if(p==k)
			{
				if(check(i,j))	i=pl;
				else
				{
					ans++;
					for(int q=i;q<=j;q++)	b[q]=true;
					i=j;
				}
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
