#include<bits/stdc++.h>
using namespace std;
int a[20];
const long long M=998244353;
int main()
{	
	//40pts
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	long long ans=0;
	int k;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		//cout<<i;
	}
	//	cout<<787878;
	//time_t qq=time(0);
	int mk=pow(2,n);
	for(k=4;k<mk;k++)
	{
		int sum=0;
		int maxx=-1;
		int t=k;
		int i=0;
		while(t)
		{
			if(t&1)
			{
				sum+=a[i];
				maxx=max(maxx,a[i]);
			}
			t=t>>1;
			i++;
		}
		if(sum>(maxx<<1))
		{
			ans++;
		}
	}
	//time_t qqa=time(0);
	//cout<<qqa-qq<<endl;
	cout<<ans%M;
	return 0;
}

