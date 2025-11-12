#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	long long m[n+1];
	for(int i=1;i<=n;i++)
	cin>>m[i];
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		if(m[i]==k)
		s++;
	}
	if(k==0)
	{
		long long a[10+1]={0};
		for(int i=1;i<=n;i++)
		{
			a[m[i]]++;
			if(a[m[i]]%2==0)
			s++;
		}
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		long long w=m[i];
		for(int j=i+1;j<=n;j++)
		{
			w=w xor m[j];
			if(w==k)
			s++;
		}
	}

	cout<<s;
	return 0;
}
