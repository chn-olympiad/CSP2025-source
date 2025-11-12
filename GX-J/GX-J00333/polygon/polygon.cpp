#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0,s=0,s1;
	int a[1000005];
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=3;i++)
	{
		s+=a[i];
		s1=max(s1,a[i]);
	}
	if(s>2*s1)
	cnt++;
	cout<<cnt%998244353;
	return 0;
}
