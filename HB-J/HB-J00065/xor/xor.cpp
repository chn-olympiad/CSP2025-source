#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,a[1005],ans,la,g[1005],con[1005],sum;
bool op;
vector <int> ve[1005];
int xo(int x,int y)
{
	int re=0,er=1;
	if(x<y)swap(x,y);
	while(x>0)
	{
		if(x%2!=y%2)re+=er;
		x>>=1;
		y>>=1;
		er<<=1;
	}
	return re;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0 && a[i]!=1)op=1;
	}
	
	
	if(!op)
	{
		for(int i=1;i<=n;i++)
		{
			if(k==0)
			{
				if(a[i]==0 || (a[i]==1 && la==1))
				{
					ans++;
					la=0;
				}
				else if(a[i]==1 && la!=1) la=1;
			}
			else if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	
	
	for(int i=1;i<=n;i++)
	{
		int ui=a[i];
		if(a[i]==k)
		{
			for(int k=1;k<i;k++)
			{
				if(g[k]>=i)
				{
					ve[k].push_back(i);
					ve[i].push_back(k);
					con[k]++;
					con[i]++;
					sum++;
				}
			}
			g[i]=i;
			ans++;
			continue;
		}
		for(int j=i+1;j<=n;j++)
		{
			ui=xo(ui,a[j]);
			if(ui==k)
			{
				for(int k=1;k<i;k++)
				{
					if(g[k]>=j)
					{
						ve[k].push_back(i);
						ve[i].push_back(k);
						con[k]++;
						con[i]++;
						sum+=2;
					}
				}
				g[i]=j;
				ans++;
				break;
			}
		}
	}
	while(sum>0)
	{
		int maxn,l;
		for(int i=1;i<=n;i++)
		{
			if(con[i]>maxn)
			{
				maxn=con[i];
				l=i;
			}
		}
		ans--;
		sum-=con[l];
		con[l]=-0x3f3f3f3f;
		for(int i=0;i<ve[l].size();i++)con[ve[l][i]]--;
	}
	cout<<ans;
	return 0;
}
