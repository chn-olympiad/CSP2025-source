#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],cnt=0;
map<int,int> check;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		int s;
		cin>>s;
		s=s^k;
		a[i]=a[i-1]^s;
	}
	for(int i=0;i<=n;i++)
	{
		if(check[a[i]]==1)
		{
			cnt++;
			check.clear();
		}
		check[a[i]]=1;
	}
	cout<<cnt;
				
	return 0;
}
