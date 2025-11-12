#include<bits/stdc++.h>
#define int long long
#define pu push
#define em empty
using namespace std;
struct student{int a,h;}d[100010];
int a[100010][4],ans[4];
priority_queue<int>p[4];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;ans[0]=ans[1]=ans[2]=ans[3]=0;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3],d[i].a=max(a[i][1],max(a[i][2],a[i][3])),d[i].h=i;
		for(int i=1;i<=n;i++)
		{
			int op;
			if(d[i].a==a[d[i].h][1])op=1;
			if(d[i].a==a[d[i].h][2])op=2;
			if(d[i].a==a[d[i].h][3])op=3;
			if(ans[op]<n/2)
			{
				ans[0]+=d[i].a,ans[op]++;
				p[op].pu(max(a[d[i].h][op%3+1],a[d[i].h][(op+1)%3+1])-d[i].a);
			}
			else
			{
				if(p[op].top()+d[i].a>max(a[d[i].h][op%3+1],a[d[i].h][(op+1)%3+1]))
				{
					ans[0]+=p[op].top()+d[i].a,p[op].pop();
					p[op].pu(max(a[d[i].h][op%3+1],a[d[i].h][(op+1)%3+1])-d[i].a);
				}
				else ans[0]+=max(a[d[i].h][op%3+1],a[d[i].h][(op+1)%3+1]);
			}
		}
		cout<<ans[0]<<endl;
		while(!p[1].em())p[1].pop();
		while(!p[2].em())p[2].pop();
		while(!p[3].em())p[3].pop();
	}
	return 0;
}
