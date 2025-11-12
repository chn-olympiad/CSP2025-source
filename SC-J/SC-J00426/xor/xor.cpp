#include<bits/stdc++.h>
using namespace std;
int n,s,x;
long long a[500005],k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	cin>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x=a[i];
		a[i]=x%2;
		x=x/2;
		while(x!=0)
		{
			a[i]+=x%2*10;
			x=x/2;
		}
	}
	x=k;
	k=x%2;
	x=x/2;
	while(x!=0)
	{
		k+=x%2*10;
		x=x/2;
	}
	int ans=a[1];
	if(ans==k) s++;
	int xx=0;
	for(int i=2;i<=n;i++)
	{
		ans=ans+a[i];
		int cnt=ans;
		while(cnt!=0)
		{
			if(cnt%10==2)
			{
				if(xx=0)
				{
					ans-=2;
				}
				else
				{
					ans-=2*xx; 
				}
			}
			cnt/=10;
			xx++;
		}
		if(ans==k) s++;
	}
	cout <<s;
	return 0;
}