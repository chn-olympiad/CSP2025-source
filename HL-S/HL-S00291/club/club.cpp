#include <bits/stdc++.h>
using namespace std;
long long x[100005],y[100005],z[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,t,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long f=n/2,sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i]>>z[i];
			sum+=max(max(x[i],y[i]),z[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}