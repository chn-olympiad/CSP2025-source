#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans;
int d[5],vis[N];
struct node{
	int id,s,pos;
	bool operator<(const node& t) const{
		return s>t.s;
	}
}a[N*3];
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(vis,0,sizeof vis);
		ans=0;
		d[1]=0;
		d[2]=0;
		d[3]=0;
		int s1,s2,s3;
		for(int i=1;i<=n;i++)
		{
			cin>>s1>>s2>>s3;
			a[i].id=1;
			a[i].s=s1;
			a[i].pos=i;
			a[i+n].id=2;
			a[i+n].s=s2;
			a[i+n].pos=i;
			a[i+n*2].id=3;
			a[i+n*2].s=s3;
			a[i+n*2].pos=i;
		}
		sort(a+1,a+n*3+1);
		for(int i=1;i<=n*3;i++)
		{
			if(vis[a[i].pos]) continue;
			if(d[a[i].id]<(n/2))
			{
				d[a[i].id]++;
				vis[a[i].pos]=1;
				ans+=a[i].s;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
