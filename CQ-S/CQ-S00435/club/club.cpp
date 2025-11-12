#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct nodeA
{
	int a,b,c,id;
	bool operator<(nodeA i)const
	{
		return max(c,b)-a<max(i.c,i.b)-i.a;
	}
};
struct nodeB
{
	int a,b,c,id;
	bool operator<(nodeB i)const
	{
		return max(c,a)-b<max(i.c,i.a)-i.b;
	}
};
struct nodeC
{
	int a,b,c,id;
	bool operator<(nodeC i)const
	{
		return max(a,b)-c<max(i.a,i.b)-i.c;
	}
};
int n,ans;
void solve()
{
	cin>>n;
	priority_queue<nodeA>A;
	priority_queue<nodeB>B;
	priority_queue<nodeC>C;
	bool vis[N]={0};
	ans=0;
	for(int l=1,i,j,k;l<=n;l++)
	{
		cin>>i>>j>>k;
		int valA=0,valB=0,valC=0;
		nodeA nowA;
		if(A.size())nowA=A.top();
		nodeB nowB;
		if(B.size())nowB=B.top();
		nodeC nowC;
		if(C.size())nowC=C.top();
		if(A.size()<n/2)valA=i;
		else valA=i-nowA.a+max(nowA.b,nowA.c);
		if(B.size()<n/2)valB=j;
		else valB=j-nowB.b+max(nowB.a,nowB.c);
		if(C.size()<n/2)valC=k;
		else valC=k-nowC.c+max(nowC.b,nowC.a);
		if(max({valA,valB,valC})==valA)
		{
			if(A.size()>=n/2)
			{
				A.pop();
				if(nowA.b>nowA.c)B.push({nowA.a,nowA.b,nowA.c,nowA.id});
				else C.push({nowA.a,nowA.b,nowA.c,nowA.id});
			}
			A.push({i,j,k,l});
		}
		else if(max({valA,valB,valC})==valB)
		{
			if(B.size()>=n/2)
			{
				B.pop();
				if(nowB.a>nowB.c)A.push({nowB.a,nowB.b,nowB.c,nowB.id});
				else C.push({nowB.a,nowB.b,nowB.c,nowB.id});
			}
			B.push({i,j,k,l});
		}
		else if(max({valA,valB,valC})==valC)
		{
			if(C.size()>=n/2)
			{
				C.pop();
				if(nowC.a>nowC.b)A.push({nowC.a,nowC.b,nowC.c,nowC.id});
				else B.push({nowC.a,nowC.b,nowC.c,nowC.id});
			}
			C.push({i,j,k,l});
		}
	}
	while(A.size())
	{
		ans+=A.top().a;
		A.pop();
	}
	while(B.size())
	{
		ans+=B.top().b;
		B.pop();
	}
	while(C.size())
	{
		ans+=C.top().c;
		C.pop();
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
