#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
struct node{
	int a,b,c;
}s[100010];
struct Compare{
	bool operator()(int x,int y)
	{
		return x>y;
	}
};
priority_queue<int,vector<int>,Compare> pq1;
priority_queue<int,vector<int>,Compare> pq2;
priority_queue<int,vector<int>,Compare> pq3;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		int num=n/2;
		while(!pq1.empty()) pq1.pop();
		while(!pq2.empty()) pq2.pop();
		while(!pq3.empty()) pq3.pop();
		for(int i=1; i<=n; i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a>=s[i].b && s[i].a>=s[i].c)
			{
				pq1.push(s[i].a);
				if(pq1.size()>num) pq1.pop();
			}
			else
			{
				if(s[i].b>=s[i].a && s[i].b>=s[i].c)
				{
					pq2.push(s[i].b);
					if(pq2.size()>num) pq2.pop();
				}
				else
				{
					if(s[i].c>=s[i].b && s[i].c>s[i].a)
					{
						pq3.push(s[i].c);
						if(pq3.size()>num) pq3.pop();
					}
				}
			}
		}
		while(!pq1.empty())
		{
			ans+=pq1.top();
			pq1.pop();
		}
		while(!pq2.empty())
		{
			ans+=pq2.top();
			pq2.pop();
		}
		while(!pq3.empty())
		{
			ans+=pq3.top();
			pq3.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
