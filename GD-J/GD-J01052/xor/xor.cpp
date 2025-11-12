#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n,k,x,num=0;
int xr(int c,int b,bool *o)
{
	int sum=a[c];
	if(o[c]) return 0;
	for(int i=c+1;i<=b;i++)
	{
		if(o[i]) return 0;
		sum=sum^a[i];
	}
	if(sum==k)
	{
		for(int i=c;i<=b;i++)
		{
			o[i]=1;
		}
		return 1;
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool o[n];
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		o[i]=0;
		cin>>x;
		a.push_back(x);
	}
	for(int l=0;l<n;l++)
	{
		for(int i=0;i<n-l;i++)
		{
			if(xr(i,i+l,o))
			{
				num++;
			}
		}
	}
	cout<<(num);
	return 0;
}
