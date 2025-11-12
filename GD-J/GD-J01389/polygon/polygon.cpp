#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005],cnt=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	while(b[n+1]!=1)
	{
		int i=1;
		b[1]++;
		while(b[i]==2)
		{
			b[i]=0;
			b[++i]++;
		}
		int s=0,mx=-1;
		for(int i=1;i<=n;i++)
		{
			if(b[i])
			{
				s+=a[i];
				mx=max(a[i],mx);
			}
				
		}
		if(s>2*mx) cnt++;
	}
	cout<<cnt-1;
	return 0;
} 
