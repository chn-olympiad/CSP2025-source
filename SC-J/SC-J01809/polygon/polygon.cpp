#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n);
	int maxn=-1,sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(sum>maxn*2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}