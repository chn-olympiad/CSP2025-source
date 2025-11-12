#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;

int n, m, k;
vector<pair<int, int>> e[N];
int a[20][N];
bool inC[N];
int dfn[N];
int ans[N];

void p(int l)
{
    int cnt=0;
	memset(dfn, 127, sizeof(dfn));
	memset(inC, 0, sizeof(inC));
	cnt++;
	inC[1]=true;
	dfn[1]=0;
	int ls=1;
	while(cnt<n)
	{
		for(auto ev:e[ls])
		{
			if(!inC[ev.first])
			{
				dfn[ev.first] = min(dfn[ev.first], ev.second);
			}
		}
		int minx, mindfn=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			if(mindfn>dfn[i]&&!inC[i]){
				mindfn=dfn[i];
				minx=i;
			}
		}
		inC[minx]=true;
		dfn[minx]=0;
		ls = minx;
		ans[l] += mindfn;
		cnt++;
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	bool flag=true;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1;i<=m;i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		e[x].push_back(make_pair(y, z));
		e[y].push_back(make_pair(x, z));
	}
	for(int j=1;j<=k;j++)
	for(int i=0;i<=n;i++)
	{
		scanf("%d", a[j]+i);
		if(a[j][0]!=0) flag=false;
	}
	if(k==0){
	p(1);
	printf("%d", ans[1]);}
	else {
		if(flag){
			n++;
			for(int j=1;j<=k;j++)
			for(int i=1;i<=n;i++)
			{
				e[n].push_back(make_pair(i, a[j][i]));
				e[i].push_back(make_pair(n, a[j][i]));
			}
			p(1);
			printf("%d", ans[1]);
		}
	}
	return 0;
}
