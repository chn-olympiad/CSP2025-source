#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define fi first
#define sd second
#define pb push_back
#define mk make_pair
#define endl '\n'
#define int long long
namespace wilbur
{
	const int N=1e5+50;
	int cas,n;
	int lim;
	struct node{
		int a,b,c;
	}x[N];
	int d[N],y[N];
	void solve()
	{
		cin>>n;
		lim=n/2;
		for(int i=1;i<=n;i++)cin>>x[i].a>>x[i].b>>x[i].c;
		int cntA=0,cntB=0,cntC=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(x[i].a>=max(x[i].b,x[i].c))
			{
				ans+=x[i].a;
				cntA++;
				d[i]=1;
				continue;
			}
			if(x[i].b>=max(x[i].a,x[i].c))
			{
				ans+=x[i].b;
				cntB++;
				d[i]=2;
				continue;
			}
			if(x[i].c>=max(x[i].a,x[i].b))
			{
				ans+=x[i].c;
				cntC++;
				d[i]=3;
				continue;
			}
			d[i]=1;
			cntA++;
			ans+=x[i].a;
		}
		if(cntA>lim)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)if(d[i]==1)y[++cnt]=max(x[i].b,x[i].c)-x[i].a;
			sort(y+1,y+1+cnt);reverse(y+1,y+1+cnt);
			for(int i=1;i<=cntA-lim;i++)ans+=y[i];
		}
		if(cntB>lim)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)if(d[i]==2)y[++cnt]=max(x[i].a,x[i].c)-x[i].b;
			sort(y+1,y+1+cnt);reverse(y+1,y+1+cnt);
			for(int i=1;i<=cntB-lim;i++)ans+=y[i];
		}
		if(cntC>lim)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)if(d[i]==3)y[++cnt]=max(x[i].a,x[i].b)-x[i].c;
			sort(y+1,y+1+cnt);reverse(y+1,y+1+cnt);
			for(int i=1;i<=cntC-lim;i++)ans+=y[i];
		}
		cout<<ans<<endl;
	}
	int main()
	{
		cin>>cas;
		while(cas--)solve();
		return 0;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	wilbur::main();
	return 0;
}
/*
fc club.out club1.ans
fc club.out club2.ans
fc club.out club3.ans
fc club.out club4.ans
fc club.out club5.ans
*/
