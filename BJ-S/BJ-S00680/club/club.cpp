#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int a[N][5], b[N];

void work()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);

	long long tot=0;
	int sum1=0, sum2=0, sum3=0;
	for(int i=1;i<=n;i++)
	{
		int Max=max(max(a[i][1],a[i][2]),a[i][3]);
		if(Max==a[i][1])
			sum1++;
		else if(Max==a[i][2])
			sum2++;
		else
			sum3++;
		tot += Max;
	}

	if(sum1<=n/2 && sum2<=n/2 && sum3<=n/2)
	{
		printf("%lld\n",tot);
		return;
	}

	if(sum2>n/2)
	{
		for(int i=1;i<=n;i++)
			swap(a[i][1],a[i][2]);
	}
	else if(sum3>n/2)
	{
		for(int i=1;i<=n;i++)
			swap(a[i][1],a[i][3]);
	}

	tot=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i][1]-max(a[i][2],a[i][3]);
		tot += max(a[i][2],a[i][3]);
	}

	sort(b+1,b+n+1,greater<int>());
	for(int i=1;i<=n/2;i++)
		tot += b[i];
	printf("%lld\n",tot);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
		work();
	return 0;
}