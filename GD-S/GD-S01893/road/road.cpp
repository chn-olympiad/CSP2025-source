#include<iostream>
#include<algorithm>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e4+15,M=15;
struct st{
	int u,v,w;
	bool operator<(st b)const{
		return w<b.w;
	}
}s[N*M],tmp[N*M];
int m,n,k,c[M],f[N],siz[N],ans=1e18;
int fd(int x){
	if(x==f[x])return x;
	return f[x]=fd(f[x]);
}
void jian(){
	for(int i=1;i<=n;i++)f[i]=i;
	int top=0;sort(s+1,s+1+m);
	int sum=0;
	for(int i=1;i<=m;i++){
		int u=s[i].u,v=s[i].v,w=s[i].w;
		if(fd(u)!=fd(v)){
			f[fd(u)]=fd(v);
			sum+=w;
			tmp[++top]=s[i];
		}
	}
	m=top;
	for(int i=1;i<=m;i++)s[i]=tmp[i];
	ans=sum;
}
void calc(int o){
	for(int i=1;i<=n+k;i++)f[i]=i,siz[i]=1;
	int sum=0;
	for(int i=1;i<=k;i++)if(o>>(i-1)&1)sum+=c[i];
	for(int i=1;i<=m;i++){
		int u=s[i].u,v=s[i].v,w=s[i].w;
		if(u>n){
			if(o>>(u-n-1)&1);
			else continue;
		}
		int fx=fd(u),fy=fd(v);
		if(fx!=fy){
			sum+=w;
			if(siz[fx]>siz[fy])swap(fx,fy);
			f[fx]=fy;
		}
	}
	ans=min(ans,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>s[i].u>>s[i].v>>s[i].w;
	jian();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			s[++m]={i+n,j,x};
		}
	}
	sort(s+1,s+1+m);
	for(int i=0;i<(1<<k);i++)calc(i);
	cout<<ans<<endl;
}
