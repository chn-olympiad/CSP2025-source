#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define gc() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
char ibuf[1<<20],*p1,*p2;
inline void read(int &x)
{
	x=0;int f=1,ch=gc();
	for(;!isdigit(ch);ch=gc())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	x*=f; 
}

//
const int N=1e5+12;
int T,n,v[N][4],ans;
struct node{
	int id,t;
	bool operator<(const node&oth)const
	{
		return t>oth.t;
	}
};
priority_queue<node>q[4];
inline int f(int x,int k){
	if(v[x][1]>=v[x][2]&&v[x][2]>=v[x][3])
	{
		if(k==1)return 1;
		if(k==2)return 2;
		if(k==3)return 3;
	} 
	if(v[x][1]>=v[x][3]&&v[x][3]>=v[x][2])
	{
		if(k==1)return 1;
		if(k==2)return 3;
		if(k==3)return 2;
	}
	if(v[x][2]>=v[x][1]&&v[x][1]>=v[x][3])
	{
		if(k==1)return 2;
		if(k==2)return 1;
		if(k==3)return 3;
	}
	if(v[x][2]>=v[x][3]&&v[x][3]>=v[x][1])
	{
		if(k==1)return 2;
		if(k==2)return 3;
		if(k==3)return 1;
	}
	if(v[x][3]>=v[x][1]&&v[x][1]>=v[x][2])
	{
		if(k==1)return 3;
		if(k==2)return 1;
		if(k==3)return 2;
	}
	if(v[x][3]>=v[x][2]&&v[x][2]>=v[x][1])
	{
		if(k==1)return 3;
		if(k==2)return 2;
		if(k==3)return 1;
	}
	return 3;
}
inline int g(int x){
	return v[x][f(x,1)]-v[x][f(x,2)];
}
inline void solve()
{
	read(n);
	rep(i,1,n)rep(j,1,3)read(v[i][j]);
	rep(i,1,n)
	{
		int to=f(i,1);
		if(q[to].size()<=n/2-1)
		{
			q[to].push((node){i,g(i)});
			ans+=v[i][to];
		}
		else
		{
			int u=q[to].top().id;
			if(g(u)<g(i))
			{
				q[to].pop();
				q[to].push((node){i,g(i)});
				q[f(u,2)].push((node){u,0});
				ans+=v[i][to];
				ans-=g(u);
			}
			else
			{
				ans+=v[i][f(i,2)];
				q[f(i,2)].push((node){i,0});
			}
		}
	}
	cout<<ans<<'\n';
	rep(i,1,3)
	while(!q[i].empty())q[i].pop();
	ans=0;
}
signed main()
{
//	cin.tie(0)->sync_with_stdio(0);  
//	freopen("my.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--)solve();
	return 0;
}