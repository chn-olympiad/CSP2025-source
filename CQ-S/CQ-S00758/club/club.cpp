#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct nt
{
	int x,y,z;
}a[200001];
int b[200001];
void solve()
{
	cin>>n;
	int c1=0,c2=0,c3=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		int ma=max(max(a[i].x,a[i].y),a[i].z);
		if(a[i].x==ma) c1++;
		else if(a[i].y==ma) c2++;
		else c3++;
		ans+=ma; 
	}
	if(c1>n/2)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			int ma=max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].x==ma) b[++t]=ma-max(a[i].y,a[i].z);
		}
		sort(b+1,b+1+t);
		for(int i=1;i<=c1-n/2;i++) ans-=b[i];
	}
	else if(c2>n/2)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			int ma=max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].y==ma) b[++t]=ma-max(a[i].x,a[i].z);
		}
		sort(b+1,b+1+t);
		for(int i=1;i<=c2-n/2;i++) ans-=b[i];
	}
	else if(c3>n/2)
	{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			int ma=max(max(a[i].x,a[i].y),a[i].z);
			if(a[i].z==ma) b[++t]=ma-max(a[i].x,a[i].y);
		}
		sort(b+1,b+1+t);
		for(int i=1;i<=c3-n/2;i++) ans-=b[i];
	}
	cout<<ans<<"\n";
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
//we are making a brighter day, just you and me. 
