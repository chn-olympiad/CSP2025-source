#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
int c[4];
struct node
{
	int x[4],m1,m2,p,y;
}a[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x[1]>>a[i].x[2]>>a[i].x[3];
			int m1=-1,m2=-1;
			for(int j=1;j<=3;j++)
			{
				if(a[i].x[j]>m1) m2=m1,m1=a[i].x[j],a[i].p=j;
				else if(a[i].x[j]>m2) m2=a[i].x[j],a[i].y=j;
			}
			a[i].m1=m1,a[i].m2=m2;
		}
		c[1]=c[2]=c[3]=0;
		priority_queue<PII> q[4];
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(c[a[i].p]+1<=n/2)
			{
				c[a[i].p]++;
				q[a[i].p].push({-(a[i].m1-a[i].m2),i});
				ans+=a[i].m1;
				continue;
			}
			PII t=q[a[i].p].top();
			if(-t.first<a[i].m1-a[i].m2)
			{
				q[a[i].p].pop();
				ans-=a[t.second].m1,ans+=a[t.second].m2+a[i].m1;
				q[a[i].p].push({-(a[i].m1-a[i].m2),i});
			}
			else ans+=a[i].m2;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
