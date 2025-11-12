#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
priority_queue<int>qa,qb,qc;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;int ans=0;
		for(int i=1;i<=n;i++)
		{
			int a,b,c,d;cin>>a>>b>>c;
			ans+=max(a,max(b,c));
			if(a>=b&&a>=c)qa.push(max(b,c)-a);
			else if(b>=a&&b>=c)qb.push(max(a,c)-b);
			else qc.push(max(a,b)-c);
		}
		while(qa.size()>n/2)
		{
			ans+=qa.top();
			qa.pop();
		}
		while(qb.size()>n/2)
		{
			ans+=qb.top();
			qb.pop();
		}
		while(qc.size()>n/2)
		{
			ans+=qc.top();
			qc.pop();
		}
		while(!qa.empty())qa.pop();
		while(!qb.empty())qb.pop();
		while(!qc.empty())qc.pop();
		cout<<ans<<"\n";
	}
	return 0;
}