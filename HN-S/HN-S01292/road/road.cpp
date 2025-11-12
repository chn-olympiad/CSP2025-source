#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int fo,to,vl;
}a[1000010],w[2000010];
struct node{
	int val,c[10010],id;
}b[15];
int as=0,fa[10010],n,m,k,q=0,mn=1e18;
bool fl[15];
bool cmp(edge x,edge y){
	return x.vl<y.vl;
}
int find(int x){
	if(fa[x]==x)
		return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void check(){
	int ans=0,l=q;
	for(int i=1;i<=k;i++)
		ans=ans+b[i].val*fl[i];
	for(int i=1;i<=q;i++)
		w[i]=a[i];
	for(int i=1;i<=n;i++){
		fa[i]=i;
		for(int j=1;j<=k;j++){
			if(fl[j]==0)
				continue;
			l++;
			w[l].fo=i;
			w[l].to=b[j].id;
			w[l].vl=b[j].c[i]+b[j].c[b[j].id];
		}
	}
	sort(w+1,w+1+l,cmp);
	for(int i=1;i<=l;i++){
		if(find(w[i].fo)!=find(w[i].to)){
			ans=ans+w[i].vl;
			fa[find(w[i].to)]=find(w[i].fo);
		}
	}
	mn=min(mn,ans);
	return;
}
void dfs(int x)
{
	if(x==k+1){
		check();
		return;
	}
	fl[x]=0;
	dfs(x+1);
	fl[x]=1;
	dfs(x+1);
	fl[x]=0;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].fo>>a[i].to>>a[i].vl;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=k;i++){
		cin>>b[i].val;
		b[i].id=1;
		for(int j=1;j<=n;j++){
			cin>>b[i].c[j];
			if(b[i].c[j]<b[i].c[b[i].id])
				b[i].id=j;
		}
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].fo)!=find(a[i].to)){
			q++;
			a[q]=a[i];
			as+=a[i].vl;
			fa[find(a[i].to)]=find(a[i].fo);
		}
	}
	mn=as;
	dfs(1);
	cout<<mn;
	return 0;
}

