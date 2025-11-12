#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll a[4],m1,m2,p;
} q[100005];
int vis[5];
int operator<(node a,node b)
{
	return a.m1-a.m2>b.m1-b.m2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&q[i].a[1],&q[i].a[2],&q[i].a[3]);	
			if(q[i].a[1]>=q[i].a[2] && q[i].a[1]>=q[i].a[3])
			{
				vis[1]++,q[i].m1=q[i].a[1],q[i].p=1;
				if(q[i].a[2]<=q[i].a[3]) q[i].m2=q[i].a[3];
				else q[i].m2=q[i].a[2];
			}
			if(q[i].a[2]>=q[i].a[1] && q[i].a[2]>=q[i].a[3]) 
			{
				vis[2]++,q[i].m1=q[i].a[2],q[i].p=2;
				if(q[i].a[1]<=q[i].a[3]) q[i].m2=q[i].a[3];
				else q[i].m2=q[i].a[1];				
			}
			if(q[i].a[3]>=q[i].a[2] && q[i].a[3]>=q[i].a[1]) 
			{
				vis[3]++,q[i].m1=q[i].a[3],q[i].p=3;
				if(q[i].a[2]<=q[i].a[1]) q[i].m2=q[i].a[1];
				else q[i].m2=q[i].a[2];
			}
		}
		ll ans=0,p=0,cnt=0;
//		cout << vis[1] << " " << vis[2] << " " << vis[3] << endl;
		if(vis[1]>=vis[2] && vis[1]>=vis[3])
		{
			if(vis[1]<=n/2)
			{
				for(int i=1;i<=n;i++)
				{
					ans+=q[i].m1;
				}
				cout << ans << endl;
				continue;
			}
			p=1;
			sort(q+1,q+n+1);
			for(int i=1;i<=n;i++)
			{
				if(q[i].p==1 && cnt==n/2) ans+=q[i].m2;
				else
				{
					ans+=q[i].m1;
					if(q[i].p==1) cnt++;
				}
			}
			cout << ans << endl;
			continue;
		}	
		if(vis[2]>=vis[1] && vis[2]>=vis[3])
		{
			if(vis[2]<=n/2)
			{
				for(int i=1;i<=n;i++)
				{
					ans+=q[i].m1;
				}
				cout << ans << endl;
				continue;
			}
			p=1;
			sort(q+1,q+n+1);
			for(int i=1;i<=n;i++)
			{
				if(q[i].p==2 && cnt==n/2) ans+=q[i].m2;
				else
				{
					ans+=q[i].m1;
					if(q[i].p==2) cnt++;
				}
//				cout << ans << " " << cnt << endl;
			}
			cout << ans << endl;
			continue;
		}
		if(vis[3]>=vis[2] && vis[3]>=vis[1])
		{
			if(vis[3]<=n/2)
			{
				for(int i=1;i<=n;i++)
				{
					ans+=q[i].m1;
				}
				cout << ans << endl;
				continue;
			}
			p=1;
			sort(q+1,q+n+1);
			for(int i=1;i<=n;i++)
			{
				if(q[i].p==3 && cnt==n/2) ans+=q[i].m2;
				else
				{
					ans+=q[i].m1;
					if(q[i].p==3) cnt++;
				}
			}
			cout << ans << endl;
			continue;
		}		
	}
	return 0;
} 
//Ren5Jie4Di4Ling5%
