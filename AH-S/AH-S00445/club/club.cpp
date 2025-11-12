#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nd
{
	int a,b,c,m1,m2,m3;
}x[1000005];
int s[5];
bool cmp(nd xx,nd yy)
{
	if (xx.m1-xx.m2!=yy.m1-yy.m2) 
		return xx.m1-xx.m2>yy.m1-yy.m2;
	else if (xx.m2-xx.m3!=yy.m2-yy.m3)
		return xx.m2-xx.m3>yy.m2-yy.m3;
	else
		return xx.m1-xx.m3>yy.m1-yy.m3;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i].a>>x[i].b>>x[i].c;
			int t1=x[i].a,t2=x[i].b,t3=x[i].c;
			if (t1<t2) swap(t1,t2);
			if (t1<t3) swap(t1,t3);
			if (t2<t3) swap(t2,t3);
			x[i].m1=t1;
			x[i].m2=t2;
			x[i].m3=t3;
		}
		sort(x+1,x+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int k1,k2,k3;
			if (x[i].m1==x[i].a) k1=1;
			if (x[i].m1==x[i].b) k1=2;
			if (x[i].m1==x[i].c) k1=3;
			if (x[i].m2==x[i].a) k2=1;
			if (x[i].m2==x[i].b) k2=2;
			if (x[i].m2==x[i].c) k2=3;
			if (x[i].m3==x[i].a) k3=1;
			if (x[i].m3==x[i].b) k3=2;
			if (x[i].m3==x[i].c) k3=3;
			if (s[k1]<n/2) ans+=x[i].m1,s[k1]++;
			else if (s[k2]<n/2) ans+=x[i].m2,s[k2]++;
				else ans+=x[i].m3,s[k3]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
