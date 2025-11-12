#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N=1e5+10;
priority_queue<int,vector<int>,greater<int> > qa,qb,qc;
int m[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(a<=max(b,c)&&a>=min(b,c))m[i]=max(a,max(b,c))-a;
			else if(b<=max(a,c)&&b>=min(a,c))m[i]=max(a,max(b,c))-b;
			else m[i]=max(a,max(b,c))-c;
			if(a>=b&&a>=c)
			{
				if(qa.size()<n/2)qa.push(m[i]),ans+=a;
				else if(qa.top()<m[i])
				{
					ans+=m[i]-qa.top()+max(b,c);
					qa.pop();
					qa.push(m[i]);
				}
				else ans+=max(b,c);
			}
			else if(b>=a&&b>=c)
			{
				if(qb.size()<n/2)qb.push(m[i]),ans+=b;
				else if(qb.top()<m[i])
				{
					ans+=m[i]-qb.top()+max(a,c);
					qb.pop();
					qb.push(m[i]);
				}
				else ans+=max(a,c);
			}
			else
			{
				if(qc.size()<n/2)qc.push(m[i]),ans+=c;
				else if(qc.top()<m[i])
				{
					ans+=m[i]-qc.top()+max(a,b);
					qc.pop();
					qc.push(m[i]);
				}
				else ans+=max(a,b);
			}
		}
		while(!qa.empty())qa.pop();
		while(!qb.empty())qb.pop();
		while(!qc.empty())qc.pop();
		cout<<ans<<endl;
	}
	return 0;
}
