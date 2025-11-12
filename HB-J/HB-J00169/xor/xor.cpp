#include <bits/stdc++.h>
using namespace std;
int a[500005],cnt=0,res=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		int flag=0;
		res++;
		for(int j=1;j<=res;j++)
		{
			a[j]=(a[j]^t);
			if((a[j])==k)
				flag=1;
		}
		if(flag==1)
		{
			cnt++;
			res=0;
			memset(a,0,sizeof(a));
		}
	}
	cout<<cnt;
	return 0;
}
