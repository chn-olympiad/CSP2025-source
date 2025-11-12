#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		int sum=0;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
			sum+=a[i];
		if(sum>(a[3]*2))
			cout<<1;
		else 
			cout<<0;
		return 0;
	}
	return 0;
}
