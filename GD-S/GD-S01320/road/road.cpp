#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,cnt,tot,f[10020],a[20][10010],c[20],fl;
struct node{
	int u,v,w;
}e[3000010],e1[200010];
int cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cnt++;
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)fl=1;
		int minn=1e18;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			minn=min(minn,a[i][j]);
		//	
		}
		if(minn!=0)fl=1;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(!fl||k==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++cnt].u=n+i,e[cnt].v=j,e[cnt].w=a[i][j];
			}
		}
		sort(e+1,e+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			u=find(u),v=find(v);
			if(u!=v){
				f[u]=v;
				tot++;
				ans+=w;
				if(tot==n+k-1)break;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(e+1,e+cnt+1,cmp);
	int cnt1=0;
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		u=find(u),v=find(v);
		if(u!=v){
			e1[++cnt1].u=e[i].u,e1[cnt1].v=e[i].v,e1[cnt1].w=e[i].w;
			f[u]=v;
			tot++;
		//	ans+=w;
			if(tot==n)break;
		}
	}
	cnt=cnt1;
	for(int i=1;i<=cnt;i++)e[i]=e1[i];
//	cout<<cnt<<endl;
	ans=1e18;
	for(int i=0;i<(1<<k);i++){
		int cnt1=cnt,sum=0,ds=0;
		for(int j=1;j<=cnt;j++)e1[j]=e[j];
		for(int j=0;j<k;j++){
			if((i>>j)&1){
				ds++;
				sum+=c[j+1];
				for(int z=1;z<=n;z++){
					cnt1++;
					e1[cnt1].u=n+j+1,e1[cnt1].v=z,e1[cnt1].w=a[j+1][z];
				}
			}
		}
		if(sum>=ans)continue;
		sort(e1+1,e1+cnt1+1,cmp);
		for(int j=1;j<=n+k;j++)f[j]=j;
		tot=0;
		for(int j=1;j<=cnt1;j++){
			int u=e1[j].u,v=e1[j].v,w=e1[j].w;
			u=find(u),v=find(v);
			if(u!=v){
				f[u]=v;
				tot++;
				sum+=w;
				if(sum>=ans)break;
				if(tot==n+ds-1)break;
			}
		}
		ans=min(ans,sum);
	//	cout<<ans<<endl;
	}
	cout<<ans;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
