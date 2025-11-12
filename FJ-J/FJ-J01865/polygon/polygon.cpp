#include <iostream>
#include <string>
using namespace std;
int p[5001];
int l[5001];
int c[5001];
long long more = 0;
int bag[5001];

int adds(int begin,int len)
{
	int ans = 0;
	bool is_bag = true;
	for (int i = begin;i<=begin+len-1;i++)
	{
		if (l[i]==0)
		{
			ans = -1;
			break;
		}
		ans += l[i];
	}
	return is_bag?ans:-1;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	
	for (int i = 0;i<=5000;i++)
	{
		p[i] = 0;
		bag[i]=0;
		c[i] = 0;
	}
	for (int i =0;i<n;i++)
	{
		cin >> p[i];
		c[p[i]]++;
	}
	
	long long ans =0;
	int times = 0;
	for (int i =5000;i>=0;i--)
	{
		if(p[i]!=0)
		{
			l[times] = p[i];
			times++;
		}
		if (c[i]>1)
		{
			more+=c[i]-1;
		}
	}
	int t = times;
	for(int i = 0;i<=t-2;i++)
	{
		for(int s = 1;s<=t+1;s++)
		{   
			int x = adds(i+1,s);
			if (x==-1)
			{
				break;
			}
			x-=l[i];
			if (x>0)
			{
				int w = t-i-s;
				ans += w*(w+1)/2;
				break;
			}
		}
	}
	cout<<ans-more;
	return 0;
}
