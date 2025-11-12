#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
const int M=1e4+5;
int t;
int n,m,k;
struct Node{
	int x,y,v;
	int s;
}a[N];
int fa[N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int ff[N];
int find1(int x){
	if(x==ff[x])return x;
	return ff[x]=find1(ff[x]);
}
ll ans;
ll sum;
bool cmp(Node x,Node y){
	return x.v<y.v;
}
int g[N];
int c[15][M];
int d[N];
ll u[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		ff[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		a[++t].x=x;
		a[t].y=y;
		a[t].v=z;
	}
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		u[n+i]=x;
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
			a[++t].x=n+i;
			a[t].y=j;
			a[t].v=c[i][j];
		}
	}
	
	sort(a+1,a+1+t,cmp);
	if(k==0){
		for(int i=1;i<=t;i++){
			int x=a[i].x,y=a[i].y;
			int rx=find(x),ry=find(y);
			if(rx==ry)continue;
			ans=ans+a[i].v;
			fa[rx]=ry;
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=t;i++){
		    int x=a[i].x,y=a[i].y;
		    ll v=a[i].v;
			if(x>n){
				int rx=find1(x);
				int ry=find1(y);
				if(rx==ry)continue;
				ff[rx]=ry;
				u[x]=u[x]+v;
				d[x]++;
				continue;
			}
			else if(y>n){
				int rx=find1(x);
				int ry=find1(y);
				if(rx==ry)continue;
				ff[rx]=ry;
				u[y]=u[y]+v;
				d[y]++;
				continue;
			}
			int rx=find(x),ry=find(y);
			if(rx==ry)continue;
			ans=ans+v;
			fa[rx]=ry;
			int rx1=find1(x),ry1=find1(y);
			if(rx1==ry1)continue;
			ff[rx1]=ry1;
			sum=sum+v;
		}
		for(int i=1;i<=k;i++){
			if(d[i+n]>1)sum=sum+u[n+i];
		}
		cout<<min(ans,sum);
	}
	
	return 0;
} 
