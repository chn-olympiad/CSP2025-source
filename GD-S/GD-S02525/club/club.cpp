#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct manyidu{
	int a,b,c;
}a[N];
ll n;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--)
	{
		ll m;
		cin>>m;
		memset(a,0,sizeof(a));
		ll sum1=0,sum2=0,sum3=0;
		ll ans=0;
		ll num=0;
		for(int i=1;i<=m;i++) 
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			num+=a[i].a+a[i].b+a[i].c;
		}
		if(num==0) cout<<0<<endl;
		for(int i=1;i<=m;i++)
		{
			ans+=max(max(a[i].a,a[i].b),a[i].c);
		}
		cout<<ans<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
