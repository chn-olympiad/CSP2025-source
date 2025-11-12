#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T;
int n;
struct node
{
	int a[4];
};
node tuan[MAXN];
bool cmpA(node xx,node yy)
{
	return xx.a[1]>yy.a[1];
}
bool cmpB(node xx,node yy)
{
	return xx.a[2]>yy.a[2];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int fl=0;
		int gong=0; 
		for(int i=1;i<=n;i++)
		{
			cin>>tuan[i].a[1]>>tuan[i].a[2]>>tuan[i].a[3];
			if(fl==0&&tuan[i].a[2]==0&&tuan[i].a[3]==0) fl=1;
			else if(fl==0&&tuan[i].a[2]==0) fl=2;
			gong+=tuan[i].a[1];
		}
		if(n==2)
		{
			int ans=-1;
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i==j) continue;
					ans=max(ans,tuan[1].a[i]+tuan[2].a[j]);
				}
			}
			cout<<ans;
			return 0;
		}
		else if(fl==1)
		{
			sort(tuan+1,tuan+n+1,cmpA);
			int ans=0;
			for(int i=1;i<=(n>>1);i++)
			{
				ans+=tuan[i].a[1];
			}
			cout<<ans;
			return 0;
		}
		else
		{
			if(gong>=n/2)
			{
				sort(tuan+1,tuan+n+1,cmpA);
				sort(tuan+n/2+2,tuan+n+1,cmpB);
				int ans=0;
				for(int i=1;i<=n/2;i++)
				{
					ans+=tuan[i].a[1];
				}
				for(int i=n/2+1;i<=n;i++)
				{
					ans+=tuan[i].a[2];
				}
				cout<<ans<<endl;
			}
			else
			{
				sort(tuan+1,tuan+n+1,cmpB);
				sort(tuan+n/2+2,tuan+n+1,cmpA);
				int ans=0;
				for(int i=1;i<=n/2;i++)
				{
					ans+=tuan[i].a[2];
				}
				for(int i=n/2+1;i<=n;i++)
				{
					ans+=tuan[i].a[1];
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
