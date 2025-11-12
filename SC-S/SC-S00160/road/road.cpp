#include<bits/stdc++.h>

#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 1e4 + 20;
int n,m,k,cnt,total,tot,ans = INF;
vector<pair<pair<int,int>,pair<int,int>>> edge;
int root[N],Size[N],c[N];
int f[20][20];
int Find(int x)
{
	if(root[x] == x) return x;
	return root[x] = Find(root[x]);
}
void add(int x,int y,int w)
{
	int rootx = Find(x),rooty = Find(y);
	if(rootx == rooty) return ;
	if(Size[rootx] < Size[rooty]) swap(rootx,rooty);
	cnt--;total += w;
	Size[rootx] += Size[rooty];
	root[rootx] = rooty;
	return ;
}
void init()
{
	for(int i=1;i<=n+k;i++) root[i] = i,Size[i] = 1;
}
void kul(int S)
{
	cnt = n;total = 0;
	init();
	for(int i=0;i<k;i++) if(!((1ll<<i)&S)) total += c[i+1],cnt++;
	for(pair<pair<int,int>,pair<int,int>> Aline:edge)
	{
		if((1ll<<Aline.first.second)&S) continue;
		add(Aline.second.first,Aline.second.second,Aline.first.first);
		if(cnt == 1) break;
	}
	ans = min(ans,total);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		edge.push_back(make_pair(make_pair(w,k),make_pair(x,y)));
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];if(!c[i]) tot++;
		for(int j=1;j<=n;j++) 
		{
			int x;
			cin>>x;
			edge.push_back(make_pair(make_pair(x,i-1),make_pair(i+n,j)));
		}
	}
	sort(edge.begin(),edge.end());
	if(tot == k)
	{
		kul(0);
		cout<<ans;
		return 0;
	}
	int len = (1ll<<k);
	for(int S=0;S<len;S++) kul(S);
	cout<<ans;
	return 0;
}