#include<bits/stdc++.h>
#define ff(i,n) for(int i=1;i<=n;i++)
#define rep(i,s,n) for(int i=s;i<=n;i++)
#define int long long
using namespace std;
const int N=1e4+10,M=2e6+10,mod=1e9+7;
int i,j,n,m,k,x,y,tot,z,ans=1e9;
int pa[N],a[15][N],c[15];
struct node{
	int x,y,v;
}e[M*2],e2[M*2];
int find(int x){
	if(pa[x]==x)return x;
	return pa[x]=find(pa[x]);
}
bool cmp(node a,node b){
	return a.v<b.v;
}
int kru(int n,int m,int s){
	int res=s,cnt=0;
	sort(e+1,e+1+m,cmp);
	ff(i,n)pa[i]=i;
	ff(i,m){
		int x=find(e[i].x);
		int y=find(e[i].y);
		int v=e[i].v;
		if(x!=y){
			pa[x]=y;
			res+=v;
			cnt++;
		}
		if(cnt==n-1||res>ans)break;
	}
	return res;
}
int in(){
	int w=1,res=0;
	char c;
	c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')w=-w;
		c=getchar();
	}
	while(('0'<=c&&c<='9')){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*w;
}
main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
//	cout<<n;
	ff(i,m){
		e[++tot]={in(),in(),in()};
	}
	bool p=0;
	ff(i,k){
		cin>>c[i];
		if(c[i])p=1;
		ff(j,n)a[i][j]=in();
	}
	if(!p){
		int cnt=0;
		ff(j,k){
			cnt++;
			ff(w,n)e[++tot]={j+n,w,a[j][w]};
		}
		cout<<kru(cnt,tot,0);
		return 0;
	}
	for(i=0;i<(1<<k);i++){
		int res=0,cnt=n,t=tot;
		ff(j,k){
			int x=(i>>(j-1))&1;
			if(x){
				res+=c[j];
				cnt++;
				ff(w,n)e[++t]={j+n,w,a[j][w]};
			}
		}
		if(res>=ans)continue;
		ff(i,m)e2[i]=e[i];
		ans=min(kru(cnt,t,res),ans);
		ff(i,m)e[i]=e2[i];
	}
	cout<<ans;
}
