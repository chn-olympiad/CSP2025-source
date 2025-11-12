#include<bits/stdc++.h>

using namespace std;

const int N=1e5+100;

int T;

int n;

struct Node
{
	int a,b,c;
	int mx,mxid;
	bool operator < (const Node & node)const
	{
		return mx>node.mx;
	}
}s[N];

long long ans=0;

void solve()
{
	ans=0;
	
	cin>>n; int mx=n/2;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].b>>s[i].c;
		if(s[i].a>=s[i].b and s[i].a>=s[i].c)
		{
			s[i].mx=s[i].a;
			s[i].mxid=0;
		}
		else if(s[i].b>=s[i].a and s[i].b>=s[i].c)
		{
			s[i].mx=s[i].b;
			s[i].mxid=1;
		}
		else
		{
			s[i].mx=s[i].c;
			s[i].mxid=2;
		}
	}
	
	sort(s+1,s+n+1);
	
	priority_queue<int>qq0,qq1,qq2;
	int sz0=0,sz1=0,sz2=0;
	
	for(int i=1;i<=n;i++)
	{
		int aim=s[i].mxid;
		
		if(aim==0)
		{
			if(sz0<mx)//还能塞
			{
				qq0.push(max(s[i].b-s[i].a,s[i].c-s[i].a));
				sz0++;
				ans+=s[i].mx;
			} 
			else//一旦一个满了其它的怎么放也没问题 
			{
				long long val1=s[i].a+qq0.top(),val2=s[i].b,val3=s[i].c;
				if(val1 > val2 and val1>val3)
				{
					qq0.pop();
					qq0.push(max(s[i].b-s[i].a,s[i].c-s[i].a));
					ans+=val1;
				}
				else ans+=max(val2,val3);
			}
		}
		else if(aim==1)
		{
			if(sz1<mx)//还能塞
			{
				qq1.push(max(s[i].a-s[i].b,s[i].c-s[i].b));
				sz1++;
				ans+=s[i].mx;
			} 
			else//一旦一个满了其它的怎么放也没问题 
			{
				long long val1=s[i].b+qq1.top(),val2=s[i].a,val3=s[i].c;
				if(val1 > val2 and val1>val3)
				{
					qq1.pop();
					qq1.push(max(s[i].a-s[i].b,s[i].c-s[i].b));
					ans+=val1;
				}
				else ans+=max(val2,val3);
			}
		}
		else
		{
			if(sz2<mx)//还能塞
			{
				qq2.push(max(s[i].b-s[i].c,s[i].a-s[i].c));
				sz2++;
				ans+=s[i].mx;
			} 
			else//一旦一个满了其它的怎么放也没问题 
			{
				long long val1=s[i].c+qq2.top(),val2=s[i].b,val3=s[i].a;
				if(val1 > val2 and val1>val3)
				{
					qq2.pop();
					qq2.push(max(s[i].a-s[i].c,s[i].b-s[i].c));
					ans+=val1;
				}
				else ans+=max(val2,val3);
			}
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>T;
	while(T--)
		solve();
	
	return 0;
}
