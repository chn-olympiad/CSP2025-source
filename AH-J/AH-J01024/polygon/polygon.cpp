#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long p=998244353;
int a[5001],m[5001];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int s=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],s=s*2%p;
	sort(a+1,a+n+1);
	m[0]++,m[a[1]]++,m[a[2]]++;
	if(a[1]+a[2]<=5000)
		m[a[1]+a[2]]++;
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j<=a[i];j++)
			s=(s-m[j])%p;
		for(int j=5000;j>=a[i];j--)
			m[j]=(m[j]+m[j-a[i]])%p;
	}
	s=(s-4)%p;
	if(s<0)
		s+=p;
	cout<<s<<"\n";
	return 0;
}
