#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
#define maxn 2000005
int n,m,t,a[maxn],pd[5];
struct nofe{
	int t[5],e,m1,m2,m3;
}p[maxn];
bool cmp1(nofe a,nofe b)
{
	if(a.t[a.m1]==b.t[b.m1])return a.t[a.m2]>b.t[b.m2];
	if(a.t[a.m2]==b.t[b.m2])return a.t[a.m3]>b.t[b.m3];
	return a.t[a.m1]>b.t[b.m1];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>t;
	while(t--)
	{
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			p[i].t[1]=x;
			p[i].t[2]=y;
			p[i].t[3]=z;
			p[i].t[4]=x+y+z;
			int m1,m2,m3;
			if(x>=y&&y>=z)m1=1,m2=2,m3=3;
			else if(x>=z&&z>=y)m1=1,m2=3,m3=2;
			else if(y>=x&&x>=z)m1=2,m2=1,m3=3;
			else if(y>=z&&z>=x)m1=2,m2=3,m3=1;
			else if(z>=x&&x>=y)m1=3,m2=1,m3=2;
			else if(z>=y&&y>=x)m1=3,m2=2,m3=1;
			p[i].m1=m1;
			p[i].m2=m2;
			p[i].m3=m3;
			p[i].e=i;
		}
		memset(pd,0,sizeof(pd));
		sort(p+1,p+1+n,cmp1);
		
		/////////////////////////////
		//cout<<'\n';
		//for(int i=1;i<=n;i++)cout<<p[i].e<<' '<<p[i].t[1]<<' '<<p[i].t[2]<<' '<<p[i].t[3]<<'\n';
		
		for(int i=1;i<=n;i++)
		{
			int max1=-INF,r1;
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
					int fd=1;
					if(j==k)fd=2;
					if(p[i].t[j]+p[i+1].t[k]>max1&&pd[j]+1<=n/2&&pd[k]+fd<=n/2)max1=p[i].t[j]+p[i+1].t[k],r1=j;
				}
			}
			pd[r1]++;
			ans+=p[i].t[r1];
			//cout<<n/2<<':'<<r1<<' ';
		}//cout<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}
