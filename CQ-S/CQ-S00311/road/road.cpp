#include<bits/stdc++.h>
using namespace std;
long long n,m,k,mi=LONG_LONG_MAX;
struct qzh
{
	long long x,b,flag;
};
struct q_qzh
{
	long long x,y,b;
	bool friend operator <(q_qzh o,q_qzh u)
	{
		return o.b>u.b;
	}	
};
vector<qzh>a[10015];
long long c[15];
long long b[15][10015];
long long xz[15];
long long tp[10015];
long long find_fa(long long o)
{
	if(tp[o]==o)
	{
		return o;
	}
	tp[o]=find_fa(tp[o]);
	return tp[o];
}
void lj(long long o,long long u)
{
	long long fo=find_fa(o),fu=find_fa(u);
	tp[fo]=fu;
	return;
}
long long scs(long long ds)
{
	long long s=0;
	priority_queue<q_qzh>q;
	for(long long i=1;i<=n+k;i++)
	{
		tp[i]=i;
		for(long long j=0;j<a[i].size();j++)
		{
			if(a[i][j].flag==1)
			{ 
//				cout<<i<<" "<<a[i][j].x<<" "<<a[i][j].b<<endl;
				q.push({i,a[i][j].x,a[i][j].b});
			}
		}
	}
//	cout<<"      "<<ds<<endl;
	for(long long i=1;i<ds;i++)
	{
		while(find_fa(q.top().x)==find_fa(q.top().y))
		{
//			cout<<q.top().x<<" "<<q.top().y<<" "<<find_fa(q.top().x)<<" "<<find_fa(q.top().y)<<endl;
			q.pop();
		}
//		cout<<q.top().x<<" "<<q.top().y<<endl;
		s+=q.top().b;
		lj(q.top().x,q.top().y);
		q.pop();
	}
	return s;
}
void dfs(long long num)
{
	if(num==k+1)
	{
		long long s=0,ss=0;
		for(long long i=1;i<=k;i++)
		{
			if(xz[i]==1)
			{
				s+=c[i];
				ss++;
//				cout<<i<<"  ";
				for(long long j=0;j<n;j++)
				{
					a[n+i][j].flag=1;
				}
			}
		}
//		cout<<endl;
		long long x=scs(ss+n);
		mi=min(mi,x+s);
//		cout<<x<<endl;
//		cout<<"                    "<<mi<<endl;
		for(long long i=1;i<=k;i++)
		{
			if(xz[i]==1)
			{
				for(long long j=0;j<n;j++)
				{
					a[n+i][j].flag=0;
				}
			}
		}
		return;
	}
	xz[num]=0;
	dfs(num+1);
	xz[num]=1;
	dfs(num+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		long long o,u,p;
		cin>>o>>u>>p;
		a[o].push_back({u,p,1});
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1;j<=n;j++)
		{
			cin>>b[i][j];
			a[n+i].push_back({j,b[i][j],0});
		}
	}
	dfs(1);
	cout<<mi;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
