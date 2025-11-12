#include <bits/stdc++.h>
using namespace std;
int a[200010][4];
int b[200010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		long long ans=0;
		int n;
		cin>>n;
		int k=n/2;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][0]>=max(a[i][1],a[i][2]))x++;
			else if(a[i][1]>=max(a[i][0],a[i][2]))y++;
			else z++;
			ans+=max(a[i][0],max(a[i][1],a[i][2]));
		}
		int t,in;
		if(x>k)
		{
			t=x-k;
			in=0;
		}
		else if(y>k)
		{
			t=y-k;
			in=1;
		}
		else if(z>k)
		{
			t=z-k;
			in=2;
		}
		else
		{
			cout<<ans<<endl;
			continue;
		}
		int d=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i][in]>=max(a[i][(in+1)%3],a[i][(in+2)%3]))
			{
				b[d]=a[i][in]-max(a[i][(in+1)%3],a[i][(in+2)%3]);
				d++;
			}
		}
		sort(b+1,b+d);
		for(int i=1;i<=t;i++)ans-=b[i];
		cout<<ans<<endl;
	}
	return 0;
}
