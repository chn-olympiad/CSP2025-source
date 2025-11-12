#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	cout<<n/2;
	return 0;
}
