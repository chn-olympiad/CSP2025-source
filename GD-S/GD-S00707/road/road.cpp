#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,ml,f[10015],s,c[15],v[15],z,q,w,y;
bool p[15];
struct ww{
	ll i,s;
}a[15][10005];
bool cmp1(ww a,ww b){
	return a.s<b.s;
}
struct qq{
	ll i,j,s;
}l[1000005],u[10005];
bool cmp(qq a,qq b){
	return a.s<b.s;
}
ll fd(ll x){
	if(f[x]==x)return x;
	else return f[x]=fd(f[x]);
}
void aa(ll x,ll t,ll h){
	if(x>k){
		for(int i=0;i<=k;i++)v[i]=1;
		for(int i=1;i<=n+k;i++)f[i]=i;
		for(int i=1;i<h;i++){
			while(v[0]<=m&&fd(u[v[0]].i)==fd(u[v[0]].j))v[0]++;
			z=u[v[0]].s;
			q=u[v[0]].i;
			w=u[v[0]].j;
			y=0;
			if(v[0]>m)z=1e10;
			for(int i=1;i<=k;i++){
				if(p[i]&&v[i]<=n){
					while(v[i]<=n&&fd(i+n)==fd(a[i][v[i]].i))v[i]++;
					if(a[i][v[i]].s<z&&v[i]<=n){
						z=a[i][v[i]].s;
						q=i+n;
						w=a[i][v[i]].i;
						y=i;
					}
				}
			}
			if(fd(q)!=fd(w)){
				f[fd(q)]=fd(w);
				t=t+z;
			}
			v[y]++;
		}
		s=min(s,t);
		return ;
	}
	aa(x+1,t,h);
	p[x]=1;
	aa(x+1,t+c[x],h+1);
	p[x]=0;
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&ml,&k);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=ml;i++)scanf("%lld%lld%lld",&l[i].i,&l[i].j,&l[i].s);//you have no eggs ¶ÁÈë¶¼**³¬Ê± 
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j].s);
			a[i][j].i=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp1);
	}
	sort(l+1,l+ml+1,cmp);
	for(int i=1;i<=ml;i++){
		if(fd(l[i].i)!=fd(l[i].j)){
			s=s+l[i].s;
			m++;
			u[m]=l[i];
			f[fd(l[i].i)]=fd(l[i].j);
		}
	}
	aa(1,0,n);
	printf("%lld",s);
	return 0;//zrts2
}
