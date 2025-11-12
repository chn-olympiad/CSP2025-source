#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
#define per(a,b,c) for(int a=(c);a>=(b);a--)
#define fc freopen("club.in","r",stdin),freopen("club.out","w",stdout);
#define debug(x) cout<<x<<'\n';
const int N=1e5+10;
using pii=pair<int,int>;
struct Peo{
	int v[3];
	int mx=-1,mxp=-1,mmx=-1,mmxp=-1;
	void read()
	{
		mx=mxp=mmx=mmxp=-1;
		for(int i=0;i<3;i++)
		{
			cin>>v[i];
			if(v[i]>=mx)
			{
				mmx=mx,mmxp=mxp;
				mx=v[i],mxp=i;
			}
			else if(v[i]>=mmx)
			{
				mmx=v[i],mmxp=i;
			}
		}
	}
}A[N];
struct nde{
	int num=0;
	nde(int _n)
	{
		num=_n;
	}
	friend bool operator<(nde a,nde b)
	{
		return A[a.num].mmx-A[a.num].mx<A[b.num].mmx-A[b.num].mx;
	}
};
priority_queue<nde> pq[3];
void Luo_Saisei()
{
	int n;
	cin>>n;
	for(int i=0;i<3;i++) {
		while(pq[i].size())
		{
			pq[i].pop();
		}
	}
	for(int i=1;i<=n;i++) A[i].read();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(pq[A[i].mxp].size()<n/2)//依旧直接放 
		{
			pq[A[i].mxp].push(nde{i});
			ans+=A[i].mx;
		}
		else{
			int num=pq[A[i].mxp].top().num;//找到编号
			if(A[num].mmx+A[i].mx>A[num].mx+A[i].mmx) 
			{
				pq[A[i].mxp].pop();
				pq[A[i].mxp].push(nde{i});
				pq[A[num].mmxp].push(nde{num});
				ans-=A[num].mx;
				ans+=A[num].mmx;
				ans+=A[i].mx;
			} 
			else{
				pq[A[i].mmxp].push(nde{i});
				ans+=A[i].mmx;
			}
		}
//		cout<<ans<<endl;
	}
	cout<<ans<<'\n';
}
signed main()
{
	fc;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) Luo_Saisei();
} 
