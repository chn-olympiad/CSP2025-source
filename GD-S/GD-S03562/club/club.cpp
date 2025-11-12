#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct nod
{
	int a1,a2,a3,mx,_mx;
	void _read()
	{
		cin>>a1>>a2>>a3;
		mx=max({a1,a2,a3});
		if(a1==mx) _mx=max(a2,a3);
		else if(a2==mx) _mx=max(a1,a3);
		else _mx=max(a1,a2);
		return;
	}
	bool operator <(const nod &B) const
	{
		return mx-_mx>B.mx-B._mx;
	}
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,ans=0;
		cin>>n;
		priority_queue<nod> q1,q2,q3;
		for(i=1;i<=n;i++)
		{
			nod x;
			x._read();
			if(x.a1==max({x.a1,x.a2,x.a3}))
			{
				q1.push(x);
				ans+=x.a1;
			}
			else if(x.a2==max({x.a1,x.a2,x.a3}))
			{
				q2.push(x);
				ans+=x.a2;
			}
			else
			{
				q3.push(x);
				ans+=x.a3;
			}
		}
		while(q1.size()>n/2)
		{
			ans-=q1.top().mx-q1.top()._mx;
			q1.pop();
		}
		while(q2.size()>n/2)
		{
			ans-=q2.top().mx-q2.top()._mx;
			q2.pop();
		}
		while(q3.size()>n/2)
		{
			ans-=q3.top().mx-q3.top()._mx;
			q3.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
