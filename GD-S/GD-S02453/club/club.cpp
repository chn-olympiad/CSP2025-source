#include<bits/stdc++.h>
using namespace std;
long long q,n,cnt1,cnt2,cnt3,ans;
struct node
{
	long long x,y,z,ch;
}a[100010];
bool cmp1(node aa,node bb)
{
	return min(aa.x-aa.y,aa.x-aa.z)<=min(bb.x-bb.y,bb.x-bb.z);
}
bool cmp2(node aa,node bb)
{
	return min(aa.y-aa.x,aa.y-aa.z)<=min(bb.y-bb.x,bb.y-bb.z);
}
bool cmp3(node aa,node bb)
{
	return min(aa.z-aa.x,aa.z-aa.y)<=min(bb.z-bb.x,bb.z-bb.y);
}
void solve()
{
	cin>>n;
	cnt1=cnt2=cnt3=ans=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].x>=a[i].y && a[i].x>=a[i].z)
		{
			a[i].ch=1;
			cnt1++;
			ans+=a[i].x;
		}
		else if(a[i].y>=a[i].x && a[i].y>=a[i].z)
		{
			a[i].ch=2;
			cnt2++;
			ans+=a[i].y;
		}
		else
		{
			a[i].ch=3;
			cnt3++;
			ans+=a[i].z;
		}
	}
	if(cnt1>n/2)
	{
		sort(a+1,a+1+n,cmp1);
		for(long long i=1;i<=n && cnt1>n/2;i++)
		{
			if(a[i].ch!=1) continue;
			ans-=min(a[i].x-a[i].y,a[i].x-a[i].z);
			cnt1--;
		}
	}
	else if(cnt2>n/2)
	{
		sort(a+1,a+1+n,cmp2);
		for(long long i=1;i<=n && cnt2>n/2;i++)
		{
			if(a[i].ch!=2) continue;
			ans-=min(a[i].y-a[i].x,a[i].y-a[i].z);
			cnt2--;
		}
	}
	else if(cnt3>n/2)
	{
		sort(a+1,a+1+n,cmp3);
		for(long long i=1;i<=n && cnt3>n/2;i++)
		{
			if(a[i].ch!=3) continue;
			ans-=min(a[i].z-a[i].x,a[i].z-a[i].y);
			cnt3--;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>q;
	while(q--) solve();
	return 0;
}
