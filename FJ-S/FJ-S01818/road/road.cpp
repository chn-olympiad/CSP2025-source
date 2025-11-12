#include<bits/stdc++.h>
using namespace std;
long long n,m,k,p,ans,cnt;
int fa[1000005];
struct node{
	int u,v,w;
}s[2000055];
int find(int aa)
{
	if(fa[aa]==aa)return aa;
	else
	{
		fa[aa]=find(fa[aa]);
		return fa[aa];
	}
}
void fath(int aa,int bb)
{
	int aaa=find(aa),bbb=find(bb);
	if(aaa!=bbb)fa[aaa]=bbb;
}
bool cmp(node aa,node bb)
{
	return aa.w<bb.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>s[i].u>>s[i].v>>s[i].w;
	if(k!=0)
	{
		cnt=m+1;
		for(int i=1;i<=k;i++)
		{
			cin>>p;
			for(int j=1;j<=n;j++)
			{
				cin>>s[cnt].w;
				s[cnt].u=j;
				s[cnt].v=m+i;
				cnt++;
			}
		}
	}
	cnt--;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(s+1,s+1+cnt,cmp);
	//for(int i=1;i<=cnt;i++)cout<<s[i].u<<" "<<s[i].v<<" "<<s[i].w<<"\n";
	for(int i=1;i<=cnt;i++)
	{
		if(find(s[i].u)!=find(s[i].v))
		{
			ans+=s[i].w;
			fath(s[i].u,s[i].v);
			//cout<<s[i].u<<" "<<s[i].v<<"\n";
		}
	}
	cout<<ans;
	return 0;
}
