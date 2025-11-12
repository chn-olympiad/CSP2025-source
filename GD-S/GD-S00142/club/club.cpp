#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,bg,sm,bga,sma,t[5],ans;
struct node{
	int x,y,z,b,s,c;
}a[100005];
bool cmp(node x,node y)
{
	return x.c<y.c;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		ans=0;
		t[1]=0;
		t[2]=0;
		t[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) bg=1;
			if(a[i].y>=a[i].x&&a[i].y>=a[i].z) bg=2;
			if(a[i].z>=a[i].y&&a[i].z>=a[i].x) bg=3;
			if(a[i].x<=a[i].y&&a[i].x<=a[i].z) sm=1;
			if(a[i].y<=a[i].x&&a[i].y<=a[i].z) sm=2;
			if(a[i].z<=a[i].y&&a[i].z<=a[i].x) sm=3;
			sm=6-bg-sm;
			if(bg==1) bga=a[i].x;if(sm==1) sma=a[i].x;
			if(bg==2) bga=a[i].y;if(sm==2) sma=a[i].y;
			if(bg==3) bga=a[i].z;if(sm==3) sma=a[i].z;
			a[i].b=bg;
			a[i].s=sm;
			a[i].c=bga-sma;
			t[bg]++;
		}
		stable_sort(a+1,a+n+1,cmp);
		int maxx=max(t[1],max(t[2],t[3]));
		if(maxx>n/2)
		{
			int s,cnt=0,sum=0;
			if(maxx==t[1]) s=1;
			if(maxx==t[2]) s=2;
			if(maxx==t[3]) s=3;
			for(int i=1;i<=n;i++)
			{
				if(a[i].b==s&&cnt<maxx-n/2)
				{
					cnt++;
					sum+=a[i].c;
				}
				if(a[i].b==1) ans+=a[i].x;
				if(a[i].b==2) ans+=a[i].y;
				if(a[i].b==3) ans+=a[i].z;
			}
			cout<<ans-sum<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i].b==1) ans+=a[i].x;
				if(a[i].b==2) ans+=a[i].y;
				if(a[i].b==3) ans+=a[i].z;
			}
			cout<<ans<<endl;
		}
	}
}
