#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=10101;
const int M=2010101;
ll n,m,k,val[N],dis[11][N],fa[N*20],tot,ans=1e18,d[N],top;
struct tt{ll u,v,w;}s[M],e[M];
bool cmp(tt a,tt b){return a.w<b.w;}
ll find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
ll mintr(ll tx,ll ty,ll op){
	ll res=0,sum=0;
	sort(s+1,s+m+ty+1,cmp);
	for(int i=1;i<=n+tot+tx;i++)fa[i]=i;
	for(int i=1;i<=m+ty;i++){
		if(sum>ans)return 1e18;
		ll x=find(s[i].u),y=find(s[i].v);
		if(x==y)continue;
		sum+=s[i].w;
		fa[x]=y;
		if(op)e[++res].u=s[i].u,e[res].v=s[i].v,e[res].w=s[i].w;
		if(res==n+tot+tx-1)break;
	}
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>s[i].u>>s[i].v>>s[i].w;
	for(int i=1;i<=k;i++){
		ll flag=0,c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>d[j];
			if(c+d[j]==0)flag=1;
		}
		if(flag){
			tot++;
			for(int j=1;j<=n;j++)s[++m].u=tot+n,s[m].v=j,s[m].w=d[j];
		}
		else{
			val[++top]=c;
			for(int j=1;j<=n;j++)dis[top][j]=d[j];
		}
	}
	ans=mintr(0,0,1);
	m=n+tot-1;
	for(int i=1;i<=(1<<top)-1;i++){
		ll maxn=0,num=0,h=m;
		for(int j=1;j<=m;j++)s[j]=e[j];
		for(int j=1;j<=top;j++){
			if(i&(1<<(j-1))){
				num++;
				maxn+=val[j];
				for(int k=1;k<=n;k++){
					if(dis[j][k]<=e[m].w){
						s[++h].u=num+n+tot;
						s[h].v=k;
						s[h].w=dis[j][k];
					}
				}
			}
		}
		ans=min(ans,mintr(num,h-m,0)+maxn);
	}
	cout<<ans;
	return 0;
}
