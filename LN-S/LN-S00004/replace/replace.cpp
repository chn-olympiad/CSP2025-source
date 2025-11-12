#include <bits/stdc++.h>
using namespace std;
namespace WfhKing{void Main();}
signed main(){return WfhKing::Main(),0;}
namespace WfhKing
{
	int firmax(int a,int b,int c)
	{
		if(a<b) a = b;
		if(a<c) a = c;
		return a;
	}
	int nextmax(int a,int b,int c)
	{
		if(a < b) swap(a,b);
		if(b < c) swap(b,c);
		if(a < b) swap(a,b);
		return b;
	}
	const int N=1e5+7;
	int t,n;
	long long ans;
	struct node{int val[5];}a[N];
	bool cmp(node x,node y){
		return firmax(x.val[1],x.val[2],x.val[3]) - nextmax(x.val[1],x.val[2],x.val[3]) > firmax(y.val[1],y.val[2],y.val[3]) - nextmax(y.val[1],y.val[2],y.val[3]) ;
	}
	int num[5];
	void solve()
	{
		num[1] = num[2] = num[3] = 0;
		ans = 0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int fir,sec;
			node x = a[i];
			for(int j=1;j<=3;j++) 
				if(x.val[j] == firmax(x.val[1],x.val[2],x.val[3])) fir = j;
			for(int j=1;j<=3;j++) 
				if(j!=fir && x.val[j] == nextmax(x.val[1],x.val[2],x.val[3])) sec = j;
			if(num[fir] + 1 <= n/2){ num[fir]++;ans+=x.val[fir];continue;}
			else {num[sec]++;ans += x.val[sec];continue;}
		}
		return ;
	}
	
	void Main()
	{
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) scanf("%d",&a[i].val[j]);
			solve();
			printf("%lld\n",ans);
		}
		return ;
	}
}
