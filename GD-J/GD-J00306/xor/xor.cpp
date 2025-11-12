#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[5000005];
long long cnt;
long long j;
long long to;
bool temp;
long long ls[5000005],rs[5000005];
long long as;
long long add(long long l,long long r)
{
	long long sum=a[l];
	for(long long i=l+1;i<=r;i++)
	{
		sum=sum^a[i];
	}
	return sum;
}
int main()
{ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long len=1;len<=n;len++)
	{
		for(long long i=1;i<=n-len+1;i++)
		{
			j=i+len-1;
			for(long long dou=1;dou<=as;dou++)
			{
				if(temp) break;
				if(i>=ls[dou]&&i<=rs[dou]) temp=true;
				if(j>=ls[dou]&&j<=rs[dou]) temp=true;
				if(i<=ls[dou]&&j>=rs[dou]) temp=true;
				if(i>=ls[dou]&&j<=rs[dou]) temp=true;
			}
			if(temp)
			{
				temp=false;
				continue;
			}
			if(add(i,j)==k)
			{
				cnt++;
				ls[++as]=i,rs[as]=j;
			}
		}
	}
	cout<<cnt;
	return 0;	
} 
