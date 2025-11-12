#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans,c[16],b[100006],bb[100006],q[16][10006];
struct sg{
	long long x,y,z;
}a[2000006];
bool cmp(sg x,sg y){
	return x.z<y.z;
}
long long cz(long long x){
	if(x==bb[x]) return x;
	return bb[x]=cz(bb[x]);
}
long long kd(){
	long long z=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') z=z*10+c-'0',c=getchar();
	return z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++) bb[i]=i;
	for(long long i=1,u,v,z;i<=m;i++){
		u=kd(),v=kd(),z=kd();
		if(u>v) swap(u,v);
		a[i]={u,v,z};
	}
	sort(a+1,a+1+m,cmp);
	long long s=0;
	for(long long i=1;i<=k;i++){
		c[i]=kd(),s+=c[i],b[i]=1;
		for(long long j=1;j<=n;j++) q[i][j]=kd();
	}
	for(long long i=1;i<=m;i++){
		long long xb=cz(a[i].x),yb=cz(a[i].y);
		if(xb==yb) continue;
		bb[yb]=xb;
		long long mn=a[i].z,kk=0;
		for(long long j=1;j<=k;j++)
			if(q[j][a[i].x]+q[j][a[i].y]+b[j]*c[j]<=mn) mn=q[j][a[i].x]+q[j][a[i].y]+b[j]*c[j],kk=j;
		b[kk]=0;
		ans+=mn;
	}
	if(s==0&&k){
			for(long long i=1;i<=n;i++)
			for(long long j=i+1;j<=n;j++){
				long long mn=1e18;
				for(long long w=1;w<=k;w++)
					mn=min(mn,q[w][i]+q[w][j]);
				a[++m]={i,j,mn};
			}
		long long d=0;
		sort(a+1,a+1+m,cmp);
		for(long long i=1;i<=n;i++) bb[i]=i;
		for(long long i=1;i<=m;i++){
			long long xb=cz(a[i].x),yb=cz(a[i].y);
			if(xb==yb) continue;
			bb[yb]=xb;
			long long mn=a[i].z,kk=0;
			for(long long j=1;j<=k;j++)
				if(q[j][a[i].x]+q[j][a[i].y]+b[j]*c[j]<=mn) mn=q[j][a[i].x]+q[j][a[i].y]+b[j]*c[j],kk=j;
			b[kk]=0;
			d+=mn;
		}
		ans=min(ans,d);
	}
	cout<<ans;
	return 0;
}
