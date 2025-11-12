#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
priority_queue<int,vector<int>,greater<int> > q[3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<3;i++) while(!q[i].empty()) q[i].pop(); 
		int ans=0,sl[3]={0,0,0};
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			int a[3];
			scanf("%d%d%d",&a[0],&a[1],&a[2]);
			int maxn=max(a[0],max(a[1],a[2]));ans+=maxn;
			if(maxn==a[0]) sl[0]++,q[0].push(a[0]-max(a[1],a[2]));
			else if(maxn==a[1]) sl[1]++,q[1].push(a[1]-max(a[0],a[2]));
			else if(maxn==a[2]) sl[2]++,q[2].push(a[2]-max(a[0],a[1]));
		}
		for(int i=0;i<3;i++) while(sl[i]>n/2) sl[i]--,ans-=q[i].top(),q[i].pop();
		printf("%d\n",ans);
	}
	return 0;
 } 
