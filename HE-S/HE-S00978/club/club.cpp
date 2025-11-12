#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,ans,f[4];
struct node {
	int x,y,z,maxn,t;
} a[100010];
bool cmp(node l,node r) {
	return l.maxn>r.maxn;
}
void solve() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		a[i].maxn=0;
	}
	f[1]=f[2]=f[3]=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i].x;
		if(a[i].maxn<=a[i].x) a[i].maxn=a[i].x,a[i].t=1;
		cin>>a[i].y;
		if(a[i].maxn<=a[i].y) a[i].maxn=a[i].y,a[i].t=2;
		cin>>a[i].z;
		if(a[i].maxn<=a[i].z) a[i].maxn=a[i].z,a[i].t=3;
	}
	sort(a+1,a+1+n,cmp);
	if(n==2)
	{
		if(a[1].t==a[2].t)
		{
			if(a[1].t==1)
			{
				if(max(a[1].maxn+a[2].y,a[1].maxn+a[2].z)<max(a[2].maxn+a[1].y,a[2].maxn+a[1].z))
				{
					cout<<max(a[2].maxn+a[1].y,a[2].maxn+a[1].z)<<endl;
					return;
				}else
				{
					cout<<max(a[1].maxn+a[2].y,a[1].maxn+a[2].z)<<endl;
					return;
				}
			}else if(a[2].t==2)
			{
				if(max(a[1].maxn+a[2].x,a[1].maxn+a[2].z)<max(a[2].maxn+a[1].x,a[2].maxn+a[1].z))
				{
					cout<<max(a[2].maxn+a[1].x,a[2].maxn+a[1].z)<<endl;
					return;
				}else
				{
					cout<<max(a[1].maxn+a[2].x,a[1].maxn+a[2].z)<<endl;
					return;
				}
			}
			else
			{
				if(max(a[1].maxn+a[2].x,a[1].maxn+a[2].y)<max(a[2].maxn+a[1].x,a[2].maxn+a[1].y))
				{
					cout<<max(a[2].maxn+a[1].x,a[2].maxn+a[1].y)<<endl;
					return;
				}else
				{
					cout<<max(a[1].maxn+a[2].x,a[1].maxn+a[2].y)<<endl;
					return;
				}
			}
		}
	}
	for(int i=1; i<=n; i++) {
		if(f[a[i].t]<n/2) {
			ans+=a[i].maxn;
			f[a[i].t]++;
		}else
		{
			if(a[i].t==1)
			{
				if(a[i].y>=a[i].z)
				{
					ans+=a[i].y;
					f[2]++;
				}else
				{
					ans+=a[i].z;
					f[3]++;
				}
			}else if(a[i].t==2)
			{
				if(a[i].x>=a[i].z)
				{
					ans+=a[i].x;
					f[1]++;
				}else
				{
					ans+=a[i].z;
					f[3]++;
				}
			}else
			{
				if(a[i].x>=a[i].y)
				{
					ans+=a[i].x;
					f[1]++;
				}else
				{
					ans+=a[i].y;
					f[2]++;
				}
			}
		}
	}
	cout<<ans<<endl;

}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		solve();
	}
	return 0;
}
