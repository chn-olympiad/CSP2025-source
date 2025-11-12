#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int f[10107];

int find(int now)
{
	
	if(f[now]==now)
	{
		
		return now;
		
	}
	
	f[now]=find(f[now]);
	
	return f[now];
	
}

struct ls
{
	
	long long u, v, w;
	
};

bool cmp(ls U, ls V)
{
	
	return U.w<V.w;
	
}

vector<ls> a;
long long ans=0;

void kru()
{
	
	int cnt=0;
	
	for(auto pa:a)
	{
		
		int A=find(pa.u);
		int B=find(pa.v);
		
		if(A==B)
		{
			
			continue;
			
		}
		
		f[A]=B;
		cnt++;
		ans+=pa.w;
		
		if(cnt==n-1)
		{
			
			return;
			
		}
		
	}
	
}

int main()
{
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin>>n>>m>>k;
	
	for(int i=0;i<=n+k;i++)
	{
		
		f[i]=i;
		
	}
	
	long long u, v, w;
	
	for(int i=0;i<m;i++)
	{
		
		//cin>>a[i].u>>a[i].v>>a[i].w;
		
		cin>>u>>v>>w;
		ls now;
		now.u=u;
		now.v=v;
		now.w=w;
		
		a.push_back(now);
		
	}
	
	for(int i=0;i<k;i++)
	{
		
		long long dian;
		cin>>dian;
		
		long long zh;
		
		for(int j=1;j<=n;j++)
		{
			
			cin>>zh;
			
			ls now;
			now.u=n+i;
			now.v=j;
			now.w=zh;
			
			a.push_back(now);
			
		}
		
	}
	
	sort(a.begin(), a.end(), cmp);
	
	kru();
		
	cout<<ans;
		
	return 0;
	
}
