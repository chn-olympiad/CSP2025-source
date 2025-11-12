#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int buc[1<<21],a[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k,ans=0,lst=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]^=a[i-1];
	}
	buc[0]++;
	for(int i=1;i<=n;i++)
	{
		if(buc[a[i]^k])
		{
//			cout<<lst<<" "<<i<<'\n';
			for(int j=lst;j<i;j++)buc[a[j]]--;
			ans++,lst=i;
		}
		buc[a[i]]++;
	}
	cout<<ans<<'\n';
	return 0;
}
//          flc
// \o/ \o/ \o/ \o/ \o/ \o/
