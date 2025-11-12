#include<bits/stdc++.h>
#define int long long
#define filein(x) freopen(x".in","r",stdin)
#define fileout(x) freopen(x".out","w",stdout)
using namespace std;
const int N=1e5+9;
struct Node
{
	int a,b,c;
	int v;
	friend bool operator<(Node x,Node y)
	{
		return x.v>y.v;
	}
};
int T,n;
vector<Node>A,B,C;
void solve()
{
	int ans=0;
	cin>>n;
	A.clear();
	B.clear();
	C.clear();
	for(int i=1;i<=n;i++)
	{
		Node p;
		cin>>p.a>>p.b>>p.c;
		p.v=0;
		if(p.a>=p.b&&p.a>=p.c)
		{
			ans+=p.a;
			p.v=min(p.a-p.b,p.a-p.c);
			A.push_back(p);
		}
		else
		{
			if(p.b>=p.a&&p.b>=p.c)
			{
				ans+=p.b;
				p.v=min(p.b-p.a,p.b-p.c);
				B.push_back(p);
			}
			else
			{
				ans+=p.c;
				p.v=min(p.c-p.a,p.c-p.b);
				C.push_back(p);
			}
		}
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	sort(C.begin(),C.end());
	while(A.size()>n/2)
	{
		ans-=A.back().v;
		A.pop_back();
	}
	while(B.size()>n/2)
	{
		ans-=B.back().v;
		B.pop_back();
	}
	while(C.size()>n/2)
	{
		ans-=C.back().v;
		C.pop_back();
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	filein("club");
	fileout("club");
	cin>>T;
	while(T--)
	solve();
	return 0;
}
/*
兵多如林
彪悍似虎
*/