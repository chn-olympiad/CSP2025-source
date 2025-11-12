#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
	int f;
} e[1100010],ans_e[10510];
int n,m,k,a[15][10010],f[10020],c[110],tot_e,tot_ans_e,tot,nn;
long long ans,ans_now;
bool v[1100010],v_now[20020];
bool cmp(node q,node h)
{
	return q.w<h.w;
}
int find_f(int now)
{
	if(f[now]==now)
		return now;
	f[now]=find_f(f[now]);
	return f[now];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].f=-1;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++){
		int f1=find_f(e[i].v),f2=find_f(e[i].u);
		if(f1!=f2){
			ans+=e[i].w;
			f[f1]=f2;
			v[i]=true;
			tot++;
		}
		if(tot>=n-1)
			break;
	}
//	cout<<ans<<"\n";
	for(int i=1;i<=m;i++)
		if(v[i])
			ans_e[++tot_ans_e]=e[i];
	nn=n;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		tot_e=tot_ans_e;
		ans_now=0;
		for(int j=1;j<=tot_ans_e;j++)
			e[j]=ans_e[j];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			e[++tot_e]=(node){nn+1,j,a[i][j],i};
		}
		sort(e+1,e+tot_e+1,cmp);
		for(int j=1;j<=nn+1;j++)
			f[j]=j;
		memset(v,0,sizeof(v));
		memset(v_now,0,sizeof(v_now));
		tot=0;
		for(int j=1;j<=tot_e;j++){
			int f1=find_f(e[j].v),f2=find_f(e[j].u);
			if(f1!=f2){
				ans_now+=e[j].w;
				f[f1]=f2;
				v[j]=true;
				if(e[j].f!=-1)
					v_now[e[j].f]=true;
				tot++;
			}
			if(tot>=nn)
				break;
		}
		for(int j=1;j<=k;j++)
			ans_now+=v_now[j]*c[j];
		if(ans_now<ans){
			ans=ans_now;
			tot_ans_e=0;
			for(int j=1;j<=tot_e;j++)
				if(v[j])
					ans_e[++tot_ans_e]=e[j];
			nn++;
		}
	}
	cout<<ans;
	return 0;
}
