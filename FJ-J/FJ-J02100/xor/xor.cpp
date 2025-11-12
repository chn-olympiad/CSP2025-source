#include <bits/stdc++.h>
using namespace std;
int n,k,a[100005],sum,num,jl,jl2;
int hs(int x)
{
	int sum2=0;
	for(int i=x;i<=n;i++)
	{
		if(a[i]==k)
		{
			jl2=i+1;
			return a[i];
		}
		if(sum2>=k)
		{
			jl2=i+1;
			return sum2;
		}
		sum2=sum2^a[i];
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(hs(jl)==k)
		{
			num++;
			jl=jl2;
		}
		else{
			jl++;
		}
	}
	cout<<num;
	return 0;
}

