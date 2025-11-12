#include<bits/stdc++.h>
#define N 400005
#define ll long long
using namespace std;
int n,a[N][3],tot,cnt[N],vis[N],pos[N];
ll f[35][35][35][35];
struct node{
	int w,x,y;
}p[N];
bool cmp(node x,node y){
	if(x.w!=y.w)return x.w>y.w;
	else return x.x<y.x;
}
void solve1(){
	for(int i=0;i<=n;i++)
		for(int x=0;x<=n/2;x++)
			for(int y=0;y<=n/2;y++)
				for(int z=0;z<=n/2;z++)f[i][x][y][z]=0;
	for(int i=1;i<=n;i++)
		for(int x=0;x<=n/2;x++)
			for(int y=0;y<=n/2;y++)
				for(int z=0;z<=n/2;z++){
					f[i][x][y][z]=0;
					if(x)f[i][x][y][z]=max(f[i][x][y][z],f[i-1][x-1][y][z]+a[i][1]);
					if(y)f[i][x][y][z]=max(f[i][x][y][z],f[i-1][x][y-1][z]+a[i][2]);
					if(z)f[i][x][y][z]=max(f[i][x][y][z],f[i-1][x][y][z-1]+a[i][3]);
				}
	ll ans=0;
	for(int x=0;x<=n/2;x++)
		for(int y=0;y<=n/2;y++)
			for(int z=0;z<=n/2;z++)
				ans=max(ans,f[n][x][y][z]);
	printf("%lld\n",ans);	
}
void solve2(){
	tot=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		p[++tot]={a[i][1],i,1};	
		p[++tot]={a[i][2],i,2};	
		p[++tot]={a[i][3],i,3};	
	}
	sort(p+1,p+tot+1,cmp);
	for(int i=1;i<=tot;i++)
		vis[i]=0,cnt[i]=0,pos[i]=0;
	for(int i=1;i<=tot;i++)
		if(!vis[p[i].x]&&cnt[p[i].y]<n/2){
			cnt[p[i].y]++;
			vis[p[i].x]=1;
			ans+=p[i].w;
			pos[p[i].x]=p[i].y;
		}
	printf("%lld\n",ans);
}
ll ans1=0;
vector<int>v[10];
ll calc(){
	ll res=0;
	for(auto x:v[1])
		res+=a[x][1];
	for(auto x:v[2])
		res+=a[x][2];
	for(auto x:v[3])
		res+=a[x][3];
	if(res>ans1){
		ans1=res;
	}
	return res;
}
double Rand(){
	return (double)rand()/RAND_MAX;
}
int x,y;
bool cmp1(int xx,int yy){
	return a[xx][y]-a[xx][x]>a[yy][y]-a[yy][x];
}
bool cmp2(int xx,int yy){
	return a[xx][x]-a[xx][y]>a[yy][x]-a[yy][y];
}
void SA(){
	ll now=ans1;
	double T=100000;
	while(T>0.001){
		x=rand()%3+1,y=rand()%3+1;
		if((v[1].size()==0&&v[2].size()==0)||(v[3].size()==0&&v[2].size()==0)||(v[1].size()==0&&v[3].size()==0))return;
		while(x==y||(v[x].size()==0||v[y].size()==0))x=rand()%3+1,y=rand()%3+1;
		sort(v[x].begin(),v[x].end(),cmp1);
		sort(v[y].begin(),v[y].end(),cmp2);
		swap(v[x][0],v[y][0]);
		ll nxt=calc();
		double de=nxt-now;
		if(de>0||exp(de/T)>Rand())now=nxt;
		else swap(v[x][0],v[y][0]);
		T*=0.98;
	}
}
void solve3(){
	tot=0;
	v[1].clear();
	v[2].clear();
	v[3].clear();
	for(int i=1;i<=n;i++){
		p[++tot]={a[i][1],i,1};	
		p[++tot]={a[i][2],i,2};	
		p[++tot]={a[i][3],i,3};	
	}
	sort(p+1,p+tot+1,cmp);
	ans1=0;
	for(int i=1;i<=tot;i++)
		vis[i]=0,cnt[i]=0,pos[i]=0;
	for(int i=1;i<=tot;i++)
		if(!vis[p[i].x]&&cnt[p[i].y]<n/2){
			cnt[p[i].y]++;
			vis[p[i].x]=1;
			ans1+=p[i].w;
			pos[p[i].x]=p[i].y;
			v[p[i].y].push_back(p[i].x);
		}
	for(int i=1;i<=100;i++)SA();
	printf("%lld\n",ans1);
	ans1=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(0));
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		bool flag=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]||a[i][3])flag=0;
		}
		tot=0;
		if(n<=30)solve1();
		else if(flag)solve2();
		else{solve3();}
	}
}
