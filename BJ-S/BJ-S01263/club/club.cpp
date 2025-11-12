#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int x,y,z,maxx,minn;
}a[N];
int lmax(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
int lmin(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
bool cmp(node n1,node n2)
{
	return (long long)(n1.maxx-(n1.x+n1.y+n1.z-n1.minn-n1.maxx))
	>(long long)(n2.maxx-(n2.x+n2.y+n2.z-n2.maxx-n2.minn));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].maxx=lmax(a[i].x,lmax(a[i].y,a[i].z));
			a[i].minn=lmin(a[i].x,lmin(a[i].y,a[i].z));
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<"\n";
			if((a[i].x>=a[i].y||cnt2==n/2)
			&&(a[i].x>=a[i].z||cnt3==n/2)&&cnt1<n/2)
				cnt1++,ans+=a[i].x;
			else if((a[i].y>=a[i].x||cnt1==n/2)
			&&(a[i].y>=a[i].z||cnt3==n/2)&&cnt2<n/2)
				cnt2++,ans+=a[i].y;
			else
				cnt3++,ans+=a[i].z;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
