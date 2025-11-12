#include<bits/stdc++.h>
using namespace std;
int s0,n,k,cnt;
int a[100005];
//vector<int> l,r;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			s0++;
		}
		for(int le=1;le<=i;le++)
		{
			int sum=0;
			for(int j=le;j<=i;j++)
			{
				if(j==le)
				{
					sum+=a[j];
				}
				else
				{
					sum^=a[j];
				}
			}
			if(sum==k)
			{
				cnt++;
//				l.push_back(le);
//				r.push_back(i);
			}
		}
	}
	if(s0==n)
	{
		if(k!=0)
		{
			cout<<0;
			exit(0);
		}
		else
		{
			cout<<n;
			exit(0);
		}
	}
	cout<<cnt;
}
