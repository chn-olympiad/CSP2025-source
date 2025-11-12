#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5,M=1e4+5,K=15,mod=1e9+7;
struct ACB{
	ll x,y,z;
	bool operator<(const ACB&o)const{
		return z<o.z;
	}
}a[N],f[K][M];
struct CBA{
	ll x,y;
	bool operator<(const CBA&z)const{
		return z.x<x;
	}
};
ll n,m,k,_k,x,y,z=1,fa[N],sum,mn,c[K],mn2,g[K],e[K],_y,_x,__y;
ll bcj(ll x){
	if(fa[x]!=x)return fa[x]=bcj(fa[x]);
	return x;
}
priority_queue<CBA>q;
struct FastIO{
	char buf[1<<21];
	ll len,pro;
	char getc(){
		if(len==pro)len=fread(buf,1,sizeof(buf),stdin),pro=0;
		return pro<len?buf[pro++]:EOF;
	}
	ll read_ll(){
		ll x=0,y=1;char c=getc();
		while(c<'0'||c>'9'){if(c=='-')y=-1;c=getc();}
		while('0'<=c&&c<='9')x=x*10+(c-'0'),c=getc();
		return x*y;
	}
	void write_ll(ll x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write_ll(x/10);
		putchar(x%10+'0');
	}
	
}io;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=io.read_ll();
	m=io.read_ll();
	k=io.read_ll();
	for(ll i=1;i<=m;i++){
		a[i].x=io.read_ll();
		a[i].y=io.read_ll();
		a[i].z=io.read_ll();
	}
	for(ll i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+m+1);
	for(ll i=1;i<=m;i++){
		x=bcj(a[i].x);
		y=bcj(a[i].y);
		if(x==y)continue;
		fa[x]=y;
		sum+=a[i].z;
		f[0][++z]=a[i];
		if(z==n)break;
	}
	mn=sum;
	for(ll i=1;i<=k;i++){
		c[i]=io.read_ll();
		for(ll j=1;j<=n;j++){
			f[i][j].z=io.read_ll();
			f[i][j].y=j;
		}
		sort(f[i]+1,f[i]+n+1);
		y=f[i][1].y;
		c[i]+=f[i][1].z;
		for(ll j=2;j<=n;j++)f[i][j].x=y;
	}
	for(ll o=(1<<k)-1;o;o--){
		_k=sum=0;
		z=1;
		fill(g,g+k+1,2);
		while(!q.empty())q.pop();
		for(ll i=1;i<=n;i++)fa[i]=i;
		for(ll i=1;i<=k;i++)if((o>>i-1)&1)e[++_k]=i;
		for(ll i=0;i<=_k;i++){
			x=e[i];
			sum+=c[x];
			q.push({f[x][2].z,x});
		}
		while(1){
			x=q.top().x;
			y=q.top().y;
			q.pop();
			__y=g[y]++;
			q.push({f[y][g[y]].z,y});
			_x=bcj(f[y][__y].x);
			_y=bcj(f[y][__y].y);
			if(_x==_y)continue;
			fa[_y]=_x;
			sum+=f[y][__y].z;
			if(++z==n)break;
		}
		mn=min(sum,mn);
	}
	io.write_ll(mn);
	return 0; 
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
