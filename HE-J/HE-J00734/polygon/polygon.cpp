#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans ","w",stdout);
	int n,maxn=99999;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a[i];
		cin>>a[i];
		sum+=a[i];
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n-3;i++)
	{
		if(sum>a[i]*2)
			sum1+=n*(i-1)/2;
	}
	cout<<sum-3*2<<endl;
	
	return 0;
}
