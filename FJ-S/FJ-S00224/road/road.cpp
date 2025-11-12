#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,f[11111],t,tt,mp[13],T;ll ans,s,y,c[12];
struct kun{int l,r;ll w;}d[2000005],e[100100];
bool cmp(kun o,kun oo){return o.w<oo.w;}
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void dfs(int x){s=0;
	if(x>=k)return;
	if(x!=0){int ss=0;int q,qq;
		for(int i=1;i<=n+k;i++){
			f[i]=i;
			if(mp[i])ss++,s+=c[i];
		}if(s>=ans)return;
		int u,v;
		for(int S=1,i=1;S<ss+n&&i<=t;i++){
			u=d[i].l,v=d[i].r;q=find(u);qq=find(v);
			if(v<=n)if(q!=qq){S++;f[q]=qq;s+=d[i].w;}
			if(v>n&&mp[v-n])if(q!=qq){S++;f[q]=qq;s+=d[i].w;}
			if(s>=ans)return;
		}
		ans=min(s,ans);
	}
	for(int i=1;i<=k;i++){
		if(!mp[i]){
			mp[i]=1;
			dfs(x+1);
			mp[i]=0;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;for(int i=1;i<=n+k;i++)f[i]=i;t=m;
	for(int i=1;i<=m;i++)scanf("%d%d%lld",&d[i].l,&d[i].r,&d[i].w);
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			t++;
			scanf("%lld",&d[t].w);
			d[t].l=j,d[t].r=n+i;
		}
	}
	sort(d+1,d+t+1,cmp);int u,v;
	for(int S=1,i=1;S<n&&i<=t;i++){
		u=d[i].l,v=d[i].r;
		//e[++tt].l=u,e[tt].r=v,e[tt].w=d[i].w;
		if(v<=n)if(find(u)!=find(v)){S++;f[find(u)]=find(v);ans+=d[i].w;}
	}if(k==0){cout<<ans;return 0;}//for(int i=1;i<=tt;i++)cout<<e[i].l<<' '<<e[i].r<<' '<<e[i].w<<"\n";
	dfs(0);cout<<ans;
	return 0;
}
/*
5 7 0
1 4 6
2 3 7
4 2 5
4 3 4
1 5 2
1 4 10
5 3 1
*/
