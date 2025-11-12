#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010];
long long t,n,s;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,greater<long long>());
		for(int i=1;i<=n/2;i++)
		{
			s+=a[i];
		}
		cout<<s;
	}
	return 0;
}
