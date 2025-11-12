#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,cnt,a[N][5],js[5],sz[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	system("fc club5.ans club.out");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		ans=cnt=0;
		memset(js,0,sizeof(js));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int ma=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ma=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==ma) js[1]++;
			else if(a[i][2]==ma) js[2]++;
			else js[3]++;
			ans+=ma;
		}
		if(js[1]<=n/2&&js[2]<=n/2&&js[3]<=n/2)
		{
			cout<<ans<<"\n";
			continue;
		}
		int hh;
		if(js[1]>n/2) hh=1;
		else if(js[2]>n/2) hh=2;
		else hh=3;
		int sy=js[hh]-n/2;
		for(int i=1;i<=n;i++)
		{
			int ma=0;
			ma=max(a[i][1],max(a[i][2],a[i][3]));
			int h1=a[i][1],h2=a[i][2],h3=a[i][3];
			if(h1>h2) swap(h1,h2);
			if(h1>h3) swap(h1,h3);
			if(h2>h3) swap(h2,h3);
			if(a[i][hh]==ma) sz[++cnt]=ma-h2;
		}
		sort(sz+1,sz+cnt+1);
		for(int i=1;i<=sy;i++) ans-=sz[i];
		cout<<ans<<"\n";
	}
	return 0;
}
