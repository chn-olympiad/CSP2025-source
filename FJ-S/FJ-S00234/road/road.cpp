#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mkp make_pair
ll n,m,k;
struct node{
	int u,v,w;
}e1[1000010],e[11][10010];
ll fa[110010],cnt,ans1,ans=999999999999999,in[110010],s[110],d[11][10010],mk[10010],cnt2;
ll pt[110],cnt1;
ll d1[11][10010];
int cmp(node x,node y){
	return x.w<y.w;
}
int find(int u){
	if(fa[u]==u)return u;
	return fa[u]=find(fa[u]);
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	if(x!=y){
		fa[x]=y;
	}
}
ll c[110];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e1[i].u>>e1[i].v>>e1[i].w;
	}
	
	sort(e1+1,e1+1+m,cmp);
	for(int i=1;i<=m&&cnt<n-1;i++){
		int x=find(e1[i].u),y=find(e1[i].v);
		if(x==y)continue;
		merge(x,y);
		e[0][++cnt]=e1[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ll mn=9999999999;
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
			e[i][j].u=n+i;
			e[i][j].v=j;
			e[i][j].w=d[i][j];
		}
		sort(e[i]+1,e[i]+1+n,cmp);
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		ll res=0,s=0;
		ll pp[11]={0};
		pp[1]=1;
		for(int j=1,l=1;l<=k;j<<=1,l++){
//			cout<<(i&j)<<endl;
			if((i&j)==0)continue;
			res+=c[l];
			pp[l]=1;
			s++;
		}
//		cout<<res<<" "<<s<<"*"<<endl;
		int now=0;
		while(now<s+n-1){
			ll pos=0,mn=9999999999;
			for(int j=0;j<=k;j++){
				if(j!=0&&(i&(1<<(j-1)))==0)continue;
				if(j==0&&pp[j]>cnt||j!=0&&pp[j]>n)continue;
//				cout<<j<<"***\n";
				if(e[j][pp[j]].w<mn){
					mn=e[j][pp[j]].w;
					pos=j;
				}
			}
			int u=e[pos][pp[pos]].u,v=e[pos][pp[pos]].v;
			pp[pos]++;
			if(find(u)==find(v))continue;
			merge(u,v);
			now++;
			res+=e[pos][pp[pos]-1].w;
//			cout<<e[pos][pp[pos]-1].w<<endl;
		}
//		cout<<res<<"&"<<endl;
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
