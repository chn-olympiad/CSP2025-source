#include<bits/stdc++.h>
using namespace std;
long long  n,a[5500],sum;
void c(int h,int k,long long s)
{
	for(int i=k+1;i<=n;i++)
	{
		s+=a[i];
		h--;
		if(!h)
		{
			if(s>2*a[i])
			{
				sum++;
				sum%=988244353;
			}
			else
				break;
		}
		else
		{
			c(h,i,s);
			s-=a[i];
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++)
	{
		c(i,0,0);
	}
	cout<<sum;
	return 0;
}
