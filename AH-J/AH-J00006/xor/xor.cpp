#include<bits/stdc++.h>
using namespace std;
int a[200005],n,k,sum;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==0)
				sum++;
		cout<<sum;
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==1)
				sum++;
		cout<<sum;
	}
	return 0;
}
