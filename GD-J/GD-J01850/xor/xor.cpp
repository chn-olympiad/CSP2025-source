#include <bits/stdc++.h>
using namespace std;
int n,ans,yee;
long long k,a[500001];
int main()
{
	int n,k;
	cin >> n,k;
	//freopen("xor.in","r",stdin)
	//freopen("xor.out","w",stdout)
	scanf("%d,%lld" ,&n ,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	yee = a[i];
	if(k)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				ans++;
			}
		}	
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
			if(a[i]==1&&a[i+1]==1)
			{
				a[i+1]=0;
			}
		}
	}
	printf("%d" ,ans);
	//fclose("xor.in")
	//fclose("xor.out")
	return 0;
}
