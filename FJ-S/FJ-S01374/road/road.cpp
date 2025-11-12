#include<bits/stdc++.h>
#define ll long long
#define N 10010
#define M 1001000
using namespace std;
ll n,m,K,num,ans1,ans,f[N],g[N],c[N],bo[N];
ll fa(ll x){
	if(f[x]==x)return x;
	return (f[x]=fa(f[x]));
}
struct node{
	ll x,y,lo,id;
}ot[M+N*10];
bool cmp(node x,node y){
	return x.lo<y.lo;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll i,j,k,x,y,z,sum,u,v;
	cin>>n>>m>>K;
	for(i=1;i<=m;i++)ot[i].id=0,cin>>ot[i].x>>ot[i].y>>ot[i].lo;
	num=m;
	for(i=1;i<=K;i++){
		cin>>c[i];
		for(j=1;j<=n;j++){
			num++;
			ot[num].x=n+i,ot[num].y=j,ot[num].id=i;
			cin>>ot[num].lo;
		}
	}
	sort(ot+1,ot+1+num,cmp);
	bo[0]=1,ans1=-1;
	for(j=0;j<=((1<<K)-1);j++){
		ans=0,sum=n;
		x=j;
		for(i=1;i<=K;i++){
			if(x&1)sum++,bo[i]=1,ans+=c[i];
			else bo[i]=0;
			x>>=1;
		}
		for(i=1;i<=n+K;i++)f[i]=i,g[i]=1;
		for(i=1;i<=num;i++){
//			cout<<ot[i].id<<" "<<bo
			if(bo[ot[i].id]==0)continue;
			x=ot[i].x,y=ot[i].y;
			u=fa(x),v=fa(y);
			if(u==v)continue;
//			cout<<x<<" "<<y<<" "<<ot[i].lo<<"\n";
			ans+=ot[i].lo;
			if(g[u]<g[v])swap(u,v);
			f[v]=u;
			g[u]+=g[v];
			if(g[u]==sum)break;
		}
//		cout<<ans<<"\n\n";
		ans1=(ans1==-1?ans:min(ans1,ans));
	}
	cout<<ans1<<"\n";
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
