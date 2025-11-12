#include<bits/stdc++.h>
using namespace std;
#define N 20005
#define K 2000005
#define ll long long
struct nd{
	ll x,y,w;
}a[K];
bool operator <(nd x,nd y){
	return x.w>y.w;
}
ll n,t,k,c[15],f[N],v[15][N],d=1,g,ans,l,lt,u[15];
ll fi(ll x){
	if(f[x]!=x)
		f[x]=fi(f[x]);
	return f[x];
}
priority_queue<nd>p;
void bfs(ll j){
	priority_queue<nd>q=p;
	for(int i=1;i<=n&&j>0;i++)
		q.push(a[t+n*j+i]);
	while(d<g){
		nd fr=q.top();
		q.pop();
		int x=fr.x,y=fr.y,w=fr.w;
		if(fi(x)!=fi(y)){
			f[fi(x)]=fi(y);
			l+=w;
			if(x>n){
				v[x-n][y]=1;
				u[x-n]++;
			}
			d++;
		}
	}
	for(int i=1;i<=j;i++){
		if(u[i]==1){
			l-=c[i];
			for(int o=1;o<=n;o++)
				if(v[i][o]==1){
					l-=a[t+n*i+o].w;
					break;
				}
		}
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>t>>k;
	for(int i=0;i<t;i++){
		scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].w);
		p.push(a[i]);
	}
	for(int i=1;i<=n;i++)
		f[i]=i;
	g=n;
	bfs(0);
	ans=l;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n+i;j++)
			f[j]=j;
		for(int j=1;j<=n;j++){
			ll x=t+n*i+j;
			for(int o=1;o<=i;o++)
				v[o][j]=u[j]=0;
			cin>>a[x].w;
			a[x].x=n+i;
			a[x].y=j;
		}
		lt+=c[i];
		l=lt;
		g++;
		d=1;
		bfs(i);
		if(l<ans){
			ans=l;
			for(int j=1;j<=n;j++)
				if(v[i][j]==1)
					p.push(a[t+n*i+j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
