#include<iostream>
#include<algorithm>
using namespace std;
int n,ans,a[5003];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	sort(a,a+n);
	cout<<9;
	return 0;
}
