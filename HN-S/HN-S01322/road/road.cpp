#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005],u,v,w[1000005],sum=0;
int main()
{
	freopen("road","r",stdin);
	freopen("road","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> u >> v >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum += w[i];
	}
	cout << sum;
	fclose(stdin);fclose(stdout);
	return 0;
}
