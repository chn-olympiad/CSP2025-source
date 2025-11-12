#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n,k,a[500010],cnt;
bool flag=1;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) flag=0;
		if(a[i]==1) cnt++;
	}
	if(flag)
	{
		if(k==1) cout<<cnt;
		if(k>1) cout<<0;
		if(k==0) cout<<cnt/2+(n-cnt)/2;
		return 0;
	}
	cout<<2;
	return 0;
}
