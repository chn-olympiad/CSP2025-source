#include <bits/stdc++.h>
#define ll long long
#define xcy rp++
using namespace std;
int n,m,k,h[10005],f[100005];
struct node{
	int u,v;
	ll w,ip;
}p[4000005],q[4000005];
int t=0;
ll ans=0;
/*
void add(int u,int v,ll w){
	p[++t].to=v;
	p[t].w=w;
	p[t].nx=h[u];
	h[u]=t;
}*/
ll c[15],a[15][10005],cl[4100],ot[4100];
int y=0;
int fd(int x){
	return f[x]==x?x:f[x]=fd(f[x]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
bool cmp2(node a,node b){
	return a.ip<b.ip;
}
void work(){
	cin>>n>>m>>k;
	for(int j=1;j<=n;j++)f[j]=j;
	for(int i=1;i<=m;i++){
		cin>>p[i].u>>p[i].v>>p[i].w;
		//p[i+m].u=p[i].v;
		//p[i+m].v=p[i].u;
		//p[i+m].w=p[i].w;
		//p[i].ip=p[i+m].ip=0;
	}
	//m*=2;
	int mp=m,hl=0;
	sort(p+1,p+1+mp,cmp);
	for(int j=1;j<=mp;j++){
		int xx=fd(f[p[j].u]),yy=fd(f[p[j].v]);
		if(xx!=yy){
			f[xx]=yy;
			ans+=p[j].w;
			hl++;
		}
		if(hl==n-1){
			break;
		}
	}
	ll anss=ans;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cl[0]=0;
	for(int i=1;i<=(1<<k)-1;i++){
		for(int j=1;j<=k;j++)if(i&(1<<(j-1))){
			cl[i]+=c[j];
		}
	}
	for(int i=1;i<=(1<<k)-1;i++){
		int fl=0;
		for(int ii=1;ii<=y;ii++)if((i&ot[ii])==ot[ii]){
			fl=1;
			break;
		}
		if(fl)continue;
		ll op=cl[i];
		//cout<<op<<' ';
		if(op>=ans){
			ot[++y]=i;
			continue;	
		}
		int num=0;
		mp=m;
		for(int ii=1;ii<=k;ii++)if(i&(1<<(ii-1))){
			num++;
			for(int j=1;j<=n;j++){
				p[++mp]=(node){n+num,j,a[ii][j],1};
				//p[++mp]=(node){j,n+num,a[ii][j],1};
			}
		}
		for(int j=1;j<=n+num;j++)f[j]=j;
		hl=0;
		sort(p+1,p+1+mp,cmp);
		for(int j=1;j<=mp;j++){
			int xx=fd(f[p[j].u]),yy=fd(f[p[j].v]);
			if(xx!=yy){
				f[xx]=yy;
				op+=p[j].w;
				hl++;
			}
			if(hl==n+num-1){
				if(op<ans)ans=op;
				else if(op-anss==cl[i])ot[++y]=i;
				break;
			}
		}
		sort(p+1,p+1+m,cmp2);
		//cout<<op<<"\n";
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	work();
	return 0;
}

