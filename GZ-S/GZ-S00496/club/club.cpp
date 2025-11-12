//GZ-S00496 贵阳市第三中学 马俊杰 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
struct node
{
	int x,y,z;
}a[N];
bool cmp(node m,node n)
{
	return m.x>n.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n==2)
		{
			int o=max(a[1].x,a[2].x),p=max(a[1].y,a[2].y),t=max(a[1].z,a[2].z);
			int ans=max(p,o);
			ans=max(ans,t);
			cout<<ans<<'\n';
			continue;
		}
		sort(a+1,a+1+n,cmp);
		int sum=0;
		for(int i=1;i<=n/2;i++)
		{
			sum+=a[i].x;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
