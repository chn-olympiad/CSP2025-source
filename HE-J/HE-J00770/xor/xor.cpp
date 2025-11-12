#include<bits/stdc++.h>
using namespace std;
int yh(int n,int m)
{
	int i=0;
	int res=0; 
	while(n||m)
	{
		if(n%2!=m%2)
		{
			res+=pow(2,i);
		}
		n/=2;
		m/=2;
		i++;
	}
	return res;
}
int main()
{
	int n,m,sum=0;
	cin>>n>>m;
	vector<int> a;
	vector<int> s;
	int b;
	for(int i=0;i<n;i++)
	{
		cin>>b;
		a.push_back(b);
	}
	if(a[0]==m)
	{
		sum++;
	}
	int q=-1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==m)
		{
			sum++;
			q=i;
			continue;
		}
		if(q!=i-1)
		{
			int tmp=a[i];
			for(int j=i+1;j>=q+1;j--)
			{
				tmp=yh(tmp,a[j]);
				if(tmp==m)
				{
					sum++;
					q=i;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
