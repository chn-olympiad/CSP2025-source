#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
struct qq{int x,y,z;}a[100005];
int cnt1,cnt2,cnt3;
int c(qq x){
	return max(x.x,max(x.y,x.z))-(x.x+x.y+x.z-max(x.x,max(x.y,x.z))-min(x.x,min(x.y,x.z)));
}
bool cmp(qq x,qq y){
	return c(x)>c(y);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].x>a[i].y&&a[i].x>a[i].z)
			{
				if(cnt1<n/2)
				{
					cnt1++; ans+=a[i].x;
				}
				else
				{
					if(a[i].y>a[i].z) {cnt2++;ans+=a[i].y;}
					else {cnt3++;ans+=a[i].z;}
				}
			}
			else if(a[i].y>a[i].z)
			{
				if(cnt2<n/2)
				{
					cnt2++; ans+=a[i].y;
				}
				else
				{
					if(a[i].x>a[i].z) {cnt1++;ans+=a[i].x;}
					else {cnt3++;ans+=a[i].z;}
				}
			}
			else
			{
				if(cnt3<n/2)
				{
					cnt3++; ans+=a[i].z;
				}
				else
				{
					if(a[i].x>a[i].y) {cnt1++;ans+=a[i].x;}
					else {cnt2++;ans+=a[i].y;}
				}
			}
		}
		cout<<ans<<'\n';
	}
}
