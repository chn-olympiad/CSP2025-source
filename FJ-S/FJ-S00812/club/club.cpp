#include<bits/stdc++.h>
using namespace std;
typedef long long ljl;
const int N=1e5+5;
ljl n,a[N][5],T,ans[N],vec[N],c[N],S;
struct NODE{
	ljl a[5];
	bool operator < (const NODE &x)const{
		return a[1]>x.a[1];
	}
}node[N];
void dfs(int st,int ca,int cb,int cc)
{
	if(ca>n/2||cb>n/2||cc>n/2)return;
	if(st>n)
	{
		ljl sum=0ll;
		for(int i=1;i<=n;++i)
			sum+=node[i].a[vec[i]];
		S=max(S,sum);
		return;
	}
	vec[st]=1;dfs(st+1,ca+1,cb,cc);
	vec[st]=2;dfs(st+1,ca,cb+1,cc);
	vec[st]=3;dfs(st+1,ca,cb,cc+1);
	return;
}
bool check()
{
	for(int i=1;i<=n;++i)
		if(node[i].a[2]||node[i].a[3])
			return 0;
	return 1;
}
int getsec(int i)
{
	int b[5];
	for(int j=1;j<=3;++j)
		b[j]=node[i].a[j];
	sort(b+1,b+3+1);
	for(int j=1;j<=3;++j)
		if(node[i].a[j]==b[2])
			return j;
	return 0;
}
int getmx(int i)
{
	int b[5];
	for(int j=1;j<=3;++j)
		b[j]=node[i].a[j];
	sort(b+1,b+3+1);
	for(int j=1;j<=3;++j)
		if(node[i].a[j]==b[1])
			return j;
	return 0;
}
void solve()
{
	for(int i=1;i<=n;++i)
	{
		int maxn=0,mxid=0;
		for(int j=1;j<=3;++j)
		{
			if(maxn<node[i].a[j])
			{
				maxn=node[i].a[j];
				mxid=j;
			}
		}
		if(c[mxid]+1<=n/2)
		{
			++c[mxid];ans[i]=mxid;
			continue;
		}
		int minn=100000000,id=0;
		for(int j=1;j<i;++j)
		{
			if(ans[j]==mxid)
			{
				if(minn>node[j].a[getmx(j)]-node[j].a[getsec(j)])
				{
					minn=node[j].a[getmx(j)]-node[j].a[getsec(j)];
					id=j;
				}
			}
		}
		if(minn<node[i].a[mxid])
		{
			ans[i]=mxid;
			++c[getsec(id)];
			ans[id]=getsec(id);
		}
		else
		{
			++c[getsec(i)];
			ans[i]=getsec(i);
		}
	}
	ljl sum=0;
	for(int i=1;i<=n;++i)
		sum+=node[i].a[ans[i]];
	cout<<sum<<'\n';
	return;
}
void Main()
{
	cin>>n;S=0ll;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=3;++j)
			cin>>node[i].a[j];
	if(check())
	{
		sort(node+1,node+n+1);
		for(int i=1;i<=n/2;++i)
			S+=node[i].a[1];
		cout<<S<<'\n';
		return;
	}
	if(n<=30)
	{
		dfs(1,0,0,0);
		cout<<S<<'\n';
		return;
	}
	solve();
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)Main();
	return 0;
}
