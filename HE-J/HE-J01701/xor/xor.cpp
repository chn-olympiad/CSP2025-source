#include<bits/stdc++.h>
#include<cmath>
#include<algorithm> 
using namespace std;
long long yihuo(int a,int b)
{
	long long sum=0;
	int s=1;
	while(s<max(a,b))
	{
		if(a<s||b<s)
		{
			sum+=s;
		}else
		{
			int as=a/s;
			int bs=b/s;
			if(as%2==0||(bs%2)==0)
			{
				sum+=s;
			}
		}
		s*=2;
	}
	if(s==1)
	{
		if(a%2==0||(b%2==0))
		{
			sum+=s;
		}
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	int a[n+2],ss=0;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i=0;i<n;i++)
	{
		int sum=0,ls=a[i];
		for(long long j=i;j<n;j++)
		{
			if(k==ls)
			{
				sum++;
				ls=0;
		    }
			ls+=yihuo(ls,a[j+1]);
		}
		ss=max(ss,sum);
	}
	cout<<ss;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
