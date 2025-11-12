#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[10];
long long ans;
struct node{
	int x,xi,y,yi,z,zi;
}st[200010];
bool cmp(node a,node b)
{
	if(a.x-a.y==b.x-b.y)   return a.y-a.z>b.y-b.z;
	return a.x-a.y>b.x-b.y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		ans=cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>st[i].x>>st[i].y>>st[i].z;
			st[i].xi=1;st[i].yi=2;st[i].zi=3;
			if(st[i].x<st[i].y)
			{
				swap(st[i].x,st[i].y);
				swap(st[i].xi,st[i].yi);
			}
			if(st[i].x<st[i].z)
			{
				swap(st[i].x,st[i].z);
				swap(st[i].xi,st[i].zi);
			}			
			if(st[i].y<st[i].z)
			{
				swap(st[i].y,st[i].z);
				swap(st[i].yi,st[i].zi);
			}			
		}
		sort(st+1,st+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			if(cnt[st[i].xi]+1<=n/2)
			{
				cnt[st[i].xi]++;
				ans+=st[i].x;
			}
			else if(cnt[st[i].yi]+1<=n/2)
			{
				cnt[st[i].yi]++;
				ans+=st[i].y;
			}
			else{
				cnt[st[i].zi]++;
				ans+=st[i].z;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
