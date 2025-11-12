#include <bits/stdc++.h>
using namespace std;
int a[5005];
long long cnt;
int n;
int ploy(int x,int y)
{
	long long res=0;
	int k=1;
	for(int i=y+1;i<=n;i++)
	{ 
		if(a[i+1]==a[i])
			k++;
		else
		{
			if(x>a[i])
			{
				res=res+1*k;
			}
			res+=k*ploy(x+a[i],i);
			k=1;
		}
	}
	return res;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int k=1;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j+1]==a[j])
				k++;
			else
			{
				cnt=cnt+k*ploy(a[i]+a[j],j);
				cout<<i<<" "<<j<<" "<<cnt<<endl;
				k=1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
