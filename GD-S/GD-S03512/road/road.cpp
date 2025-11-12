#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,k;
ll read(){
	ll c=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch <'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		c=c*10+ch-'0';
		ch=getchar();
	}
	return c*f;
}
struct Edge
{
	ll to,nxt,val,fa;
	bool operator <(const Edge &x)const{
		return val<x.val;
	}
}e[2000005],e1[2000005];
ll head[10015],cnt,head1[10015],ccnt;
ll c[15],a[15][10005],aans=0x3f3f3f3f3f3f3f3f,ts[10005];
bool vis[10015];
void addedge(ll u,ll v,ll w){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	e[cnt].val=w;
	e[cnt].fa=u;
}
void addedge1(ll u,ll v,ll w){
//	cout<<"add\n";
//	int ccnt=cnt;
	e1[++ccnt].to=v;
	e1[ccnt].nxt=head1[u];
	head1[u]=ccnt;
	e1[ccnt].val=w;
	e1[ccnt].fa=u;
}
bool flag;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;
//		scanf("%lld %lld %lld",&u,&v,&w);
		u=read(),v=read(),w=read();
		addedge(u,v,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i])flag=1;
		for(int j=1;j<=n;j++){
//			scanf("%d",&a[i][j]);
			a[i][j]=read();
		}
	}
	if(flag){
		for(int i=0;i<(1<<k);i++){
			memset(vis,0,sizeof vis);
	//		for(int i=1;i<=n;i++)cout<<vis[i];
			for(int j=1;j<=m;j++)e1[j]=e[j];
			for(int j=1;j<=n;j++)head1[j]=head[j];
			ccnt=cnt;
			ll ans=0,cto=0;
			for(int j=0;j<k;j++){
				if((1<<j)&i){
					ans+=c[j+1];
					for(int o=1;o<=n;o++){
						addedge1(n+j+1,o,a[j+1][o]);
					}
					cto++;
				}
			}
	//		cout<<cto<<endl;
	//		for(int i=1;i<=m+1+n*cto;i++){
	//			cout<<"edge"<<e1[i].val<<" ";
	//		}
	//		cout<<endl;
			sort(e1+1,e1+m+1+n*cto);
	//		for(int i=1;i<=m+1+n*cto;i++){
	//			cout<<"edge"<<e1[i].val<<" ";
	//		}
	//		cout<<endl;
			vis[e1[1].fa]=1;
	//		for(int lll=1;lll<=1000;lll++)
			for(int p=1,ct=0;p<=m+n*cto&&ct<=n-1+cto;p++){
				if((!vis[e1[p].to]&&vis[e1[p].fa])||(vis[e1[p].to]&&!vis[e1[p].fa])){
					ans+=e1[p].val;
					ct++;
					vis[e1[p].to]=1,vis[e1[p].fa]=1;
//					cout<<e1[p].to<<" "<<e1[p].fa<<" "<<e1[p].val<<" "<<ct<<endl;
					p=1;
				}
				
			}
//			for(int i=1;i<=n;i++)cout<<vis[i];
//			cout<<endl;
			aans=min(ans,aans);
//			cout<<ans<<endl;
		}
		cout<<aans;
	}
	else{
		ll ans=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0){
					ts[i]=j;
//					cout<<"yes";
					break;
				}
			}
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(j!=ts[i])
				addedge(ts[i],j,a[i][j]);
			}
		}
		sort(e+1,e+1+cnt);
		vis[e[1].fa]=1;
		for(int p=1,ct=0;p<=cnt&&ct<n-1;p++){
			if((!vis[e[p].to]&&vis[e[p].fa])||(vis[e[p].to]&&!vis[e[p].fa])){
					ans+=e[p].val;
					vis[e[p].to]=1,vis[e[p].fa]=1;
					ct++;
					p=1;
//					cout<<e[p].to<<" "<<e[p].fa<<" "<<e[p].val<<" "<<ct<<endl;
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
思路：先在原图求最小生成树，然后枚举每个乡镇是否需要城市化，城市化后对原图边进行松弛（？）
不对，直接枚举加最小生成树吧


*/
