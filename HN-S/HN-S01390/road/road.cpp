#include<bits/stdc++.h>
using namespace std;
struct draw{
	long long l,r,z;
	bool friend operator < (draw shu1,draw shu2){
		return shu1.z>shu2.z;
	}
}o;
struct draw2{
	long long l,r,z,id;
}b[110010];
long long n,m,k,l,r,z,num,ans,mi=1e17,a[10110],c[20],d[20];
priority_queue<draw> q;
long long zhi(long long shu){
	if(a[shu]==shu) return shu;
	a[shu]=zhi(a[shu]);
	return a[shu];
}
void zhi2(long long shu){
	if(shu>k){
		ans=0;
		for(int i=1;i<=k;i++){
			if(d[i]) ans+=c[i];
		}
		for(int i=1;i<=num;i++){
			if(d[b[i].id]==0) continue;
			q.push({b[i].l,b[i].r,b[i].z});
		} 
		for(int i=1;i<=n+k;i++) a[i]=i;
		while(q.empty( )==0){
			o=q.top( ),q.pop( );
			if(zhi(o.l)==zhi(o.r)) continue;
			ans+=o.z;
			a[zhi(o.l)]=zhi(o.r);
		}
		mi=min(mi,ans);
		return;
	}
	zhi2(shu+1);
	d[shu]=1;
	zhi2(shu+1);
	d[shu]=0;
	return;
}
int main(  ){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>l>>r>>z;
		q.push({l,r,z});
	}
	for(int i=1;i<=n;i++) a[i]=i;
	while(q.empty( )==0){
		o=q.top( ),q.pop( );
		if(zhi(o.l)==zhi(o.r)) continue;
		b[++num].l=o.l;
		b[num].r=o.r;
		b[num].z=o.z;
		b[num].id=0;
		a[zhi(o.l)]=zhi(o.r);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>l;
			b[++num].l=n+i;
			b[num].r=j;
			b[num].z=l;
			b[num].id=i;
		}
	}
	d[0]=1;
	zhi2(1);
	cout<<mi<<endl;
	return 0;
}
