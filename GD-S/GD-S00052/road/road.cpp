#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

struct Side{
	int u;
	int v;
	ll w;
};


Side  s[4000100];

bool mark[10004];

bool cmp(Side x,Side y)
{
	return x.w<y.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		cin >> s[i].u >> s[i].v >> s[i].w;
	}
	
	int p=0;
	for(int i=1;i<=k;i++)
	{
		int c;
		cin >> c;
		vector<int> a;
		a.push_back(0);
		for(int j=1;j<=n;j++)
		{
			int ca;
			cin >> ca;
			a.push_back(ca);
		}
		for(int x=1;x<=n;x++)
		{
			for(int y=x+1;y<=n;y++)
			{
				s[m+1+p].u=x;
				s[m+1+p].v=y;
				s[m+1+p].w=(a[x]+a[y]+c);
				p++;
			}
		}
	}
	
	sort(s+1,s+m+p+1,cmp);
	//______________________________
//	cerr << "所有的路:" << endl;
//	for(int i=1;i<=m+p;i++)
//	{
//		if(i==m) cerr << "__"<<endl;
//		cerr << s[i].u << "--"<<s[i].v<<" cost:"<<s[i].w<<endl; 
//	}
	//______________________________
	ll cost=0;
	int numa=0;
	for(int i=1;i<=m+p;i++)
	{
		if(numa==n) break;
		if(mark[s[i].u]!=1 || mark[s[i].v]!=1)
		{
			cost+=s[i].w;
			numa+= !(mark[s[i].u])+!(mark[s[i].v]);
			mark[s[i].u]=mark[s[i].v]=1;
		}
	}
//	cerr << "选择的路:" << endl;
//	for(int i=1;i<=m+p;i++)
//	{
//		if(s[i].marks==1)
//		{
//			cerr << s[i].u << "--"<<s[i].v<<" cost:"<<s[i].w<<endl; 
//			s[i].marks=1;
//		}
//	}
	cout << cost<<endl;
	return 0;
} 
