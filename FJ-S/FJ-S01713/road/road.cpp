#include<bits/stdc++.h>
using namespace std;

struct node{
	int to,val;
};
struct node2{
	int head,to,val;
};
int n,m,k,fa[100005];
node2 kr[10000005];

bool cmp(node2 a,node2 b)
{
	return a.val<b.val;
}

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void krl(int ed)
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(kr+1,kr+ed+1,cmp);
	int ans=0,cnt=0;;
	for(int i=1;i<=ed;i++)
	{
		int head=kr[i].head,to=kr[i].to,val=kr[i].val;
		head=find(head),to=find(to);
		if(head!=to)
		{
			fa[head]=to;
			ans+=val;
			cnt++;
		} 
		if(cnt==n-1+k) break;
	}
	cout<<ans;
	return ;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		kr[i]=(node2){x,y,z};
	}
	if(k==0)
	{
		krl(m);
		return 0;
	}
	int cnt=m;
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			int v;cin>>v;
			kr[++cnt]=(node2) {n+i,j,v};
		}
	}
	krl(cnt);
	return 0;
}