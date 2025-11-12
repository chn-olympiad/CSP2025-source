#include<bits/stdc++.h>
using namespace std;
long long n,m,mm,k,x[2000000],y[2000000],z[2000000],xx[2000000],yy[2000000],zz[2000000],c[20000],d[20][10005],sum,ans=99999999999999999;
long long f[1000000],xa,ya;
long long find(long long xxx){
	if(f[xxx]==xxx) return xxx;
	return f[xxx]=find(f[xxx]);
}
bool bz[100];
void qsort(long long l,long long r){
	long long i=l,j=r,mid=z[(l+r)/2];
	while(i<=j){
		while(z[i]<mid) i++;
		while(z[j]>mid) j--;
		if(i<=j){
			swap(x[i],x[j]);
			swap(y[i],y[j]);
			swap(z[i],z[j]);
			i++,j--;
		}
	}
	if(i<r) qsort(i,r);
	if(j>l) qsort(l,j);
}
void dp(long long xxx){
	if(xxx>k){
		sum=0;
		mm=m;
		for(long long i=1;i<=n+k;i++) f[i]=i;
		for(long long i=1;i<=m;i++){
			x[i]=xx[i];
			y[i]=yy[i];
			z[i]=zz[i];
		}
		for(long long i=1;i<=k;i++){
			if(bz[i]){
				sum+=c[i];
				for(long long j=1;j<=n;j++){
					x[++mm]=n+i;
					y[mm]=j;
					z[mm]=d[i][j];
				}
			}
		}
		qsort(1,mm);
		for(long long i=1;i<=mm;i++){
			xa=find(x[i]);
			ya=find(y[i]);
			if(xa!=ya){
				sum+=z[i];
				if(sum>=ans) return ;
				f[xa]=ya;
			}
		}
		ans=min(ans,sum);
		return ;
	}
	bz[xxx]=1; 
	dp(xxx+1);
	bz[xxx]=0;
	dp(xxx+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++) cin>>xx[i]>>yy[i]>>zz[i];
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++) cin>>d[i][j];
	}
	dp(1);
	printf("%lld",ans);
	return 0;
} 
