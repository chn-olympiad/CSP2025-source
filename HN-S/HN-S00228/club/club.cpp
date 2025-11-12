#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,cnt;
struct P
{
	int a,b,c;
}v[N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > v1,v2,v3;
void fs()
{
	while(v1.size()>cnt)
	{
		pair<int,int> x,y;
		x=v1.top();
		v1.pop();
		y=v1.top();
		v1.pop();
		if(max(v[x.second].b,v[x.second].c)>=max(v[y.second].b,v[y.second].c))
		{
			if(v[x.second].b>=v[x.second].c)
			{
				v1.push({y.first,y.second});
				v2.push({v[x.second].b,x.second});
			}
			else
			{
				v1.push({y.first,y.second});
				v3.push({v[x.second].c,x.second});
			}
		}
		else
		{
			if(v[y.second].b>=v[y.second].c)
			{
				v1.push({x.first,x.second});
				v2.push({v[y.second].b,y.second});
			}
			else
			{
				v1.push({x.first,x.second});
				v3.push({v[y.second].c,y.second});
			}	
		}
	}
	while(v2.size()>cnt)
	{
		pair<int,int> x,y;
		x=v2.top();
		v2.pop();
		y=v2.top();
		v2.pop();
		if(max(v[x.second].a,v[x.second].c)>=max(v[y.second].a,v[y.second].c))
		{
			if(v[x.second].a>=v[x.second].c)
			{
				v2.push({y.first,y.second});
				v1.push({v[x.second].a,x.second});
			}
			else
			{
				v2.push({y.first,y.second});
				v3.push({v[x.second].a,x.second});
			}
		}
		else
		{
			if(v[y.second].a>=v[y.second].c)
			{
				v2.push({x.first,x.second});
				v1.push({v[y.second].a,y.second});
			}
			else
			{
				v2.push({x.first,x.second});
				v3.push({v[y.second].c,y.second});
			}	
		}
	}
	while(v3.size()>cnt)
	{
		pair<int,int> x,y;
		x=v3.top();
		v3.pop();
		y=v3.top();
		v3.pop();
		if(max(v[x.second].b,v[x.second].a)>=max(v[y.second].b,v[y.second].a))
		{
			if(v[x.second].a>=v[x.second].b)
			{
				v3.push({y.first,y.second});
				v1.push({v[x.second].a,x.second});
			}
			else
			{
				v3.push({y.first,y.second});
				v2.push({v[x.second].b,x.second});
			}
		}
		else
		{
			if(v[y.second].a>=v[y.second].b)
			{
				v3.push({x.first,x.second});
				v1.push({v[y.second].a,y.second});
			}
			else
			{
				v3.push({x.first,x.second});
				v2.push({v[y.second].b,y.second});
			}	
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cnt=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>v[i].a>>v[i].b>>v[i].c;
			int mx=max(v[i].a,max(v[i].b,v[i].c));
			if(mx==v[i].a)
			{
				v1.push({v[i].a,i});
			}
			else if(mx==v[i].b)
			{
				v2.push({v[i].b,i});
			}
			else
			{
				v3.push({v[i].c,i});
			}
		}
		fs();
		int ans=0;
		while(v1.size())
		{
			ans+=v1.top().first;
			v1.pop();
		}
		while(v2.size())
		{
			ans+=v2.top().first;
			v2.pop();
		}
		while(v3.size())
		{
			ans+=v3.top().first;
			v3.pop();
		}
		cout<<ans<<"\n";
	}
	return 0; 
} 
