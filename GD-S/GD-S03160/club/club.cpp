#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,y,x) for(int i=(y);i>=(x);i--)
bool memst;
namespace cyzz
{
	#define N 100005
	int n,a[N],b[N],c[N];
	int ans;
	void clr(){ans=0;}
	void solve()
	{
		scanf("%d",&n);
		vector<int>A,B,C;
		rep(i,1,n)
		{
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i]&&a[i]>=c[i])
				A.eb(i),ans+=a[i];
			else if(b[i]>=a[i]&&b[i]>=c[i])
				B.eb(i),ans+=b[i];
			else
				C.eb(i),ans+=c[i];
		}
		int flaga=A.size()>n/2,flagb=B.size()>n/2,flagc=C.size()>n/2;
		if(!(flaga||flagb||flagc))
			printf("%d\n",ans);
		else
		{
			int col=1;
			if(flagb) col=2,swap(a,b),swap(A,B);
			if(flagc) col=3,swap(a,c),swap(A,C);
			vector<int>tmp;
			for(int i:A) tmp.eb(max(b[i],c[i])-a[i]);
			sort(tmp.begin(),tmp.end(),greater<int>());
			int need=A.size()-n/2;
			rep(i,0,need-1) ans+=tmp[i];
			printf("%d\n",ans);
		}
		clr();
	}
	void MAIN()
	{
		int T;scanf("%d",&T);
		while(T--) solve();
	}
}bool memed;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cyzz::MAIN();
	debug("%.2lfms %.2lfMB",1.0*clock()/CLOCKS_PER_SEC/1000,
		abs(&memst-&memed)/1024./1024);
}
