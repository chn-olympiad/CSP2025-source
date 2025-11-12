#include<bits/stdc++.h>
using namespace std;
long long a[100001],k,n,b,cnt;
long long  x[100000001],y[100000001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
		x[cnt]=i;
		y[cnt]=i;
		cnt++;
	    }
	   }
	if(k==0)cout<<"1";
	else

	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if((a[i]+a[j])%k==0)
			{
				b=0;
				for(int c=0;c<cnt;c++)
					if(!(i>y[c]||j<x[c]))
						b=1;
				if(!b)
				{
					x[cnt]=i;
					y[cnt]=j;
					cnt++;
				}
			}
	cout<<cnt;				
	return 0;
}
