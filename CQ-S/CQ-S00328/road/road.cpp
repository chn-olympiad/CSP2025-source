#include<bits/stdc++.h>
using namespace std;
long long a[2505][2505],n,m,k,x,y,w,z,c[2000005],v[2500005],ans,cnt,h,minn,e,o,cc[2000005];
struct nn{
	long long q,u,g;
}p[2000005];
bool cmp(nn x,nn y){
	return x.g<y.g;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    memset(a,0x3f3f3f3f3f,sizeof(a));
    for(long long i=1;i<=m;i++){
    	scanf("%lld%lld%lld",&x,&y,&w);
    	a[x][y]=min(w,a[x][y]);
    	a[y][x]=a[x][y];
	}
    for(long long i=1;i<=k;i++){
    	scanf("%lld",&z);
    	for(long long j=1;j<=n;j++){
    		scanf("%lld",&cc[j]);
		}
		for(long long j=1;j<=n;j++){
			for(long long l=j+1;l<=n;l++){
				a[j][l]=min(a[j][l],cc[j]+cc[l]+z);
				a[l][j]=a[j][l];
			}
		}
	}
    for(long long i=1;i<=n;i++) a[i][i]=0;
    for(long long l=1;l<=n;l++){
    	for(long long i=1;i<=n;i++){
    		if(i==l) continue;
    		for(long long j=i+1;j<=n;j++){
    		if(j==l) continue;
    		if(a[i][l]+a[l][j]<a[i][j]){
    			a[i][j]=a[i][l]+a[l][j];
    			a[j][i]=a[i][j];
			}
			}
		}
	}
    for(long long i=1;i<=n;i++){
    	for(long long j=i+1;j<=n;j++){
    	    cnt++;
			p[cnt].q=i;
			p[cnt].u=j;
			p[cnt].g=a[i][j];	
		}
	}
	sort(p+1,p+1+n,cmp);
	h++;
	c[h]=p[1].q;
	v[c[h]]=1;
	h++;
	c[h]=p[1].u;
	ans+=p[1].g;
	v[c[h]]=1;
	while(1){
		minn=0x3f3f3f3f3f;
		o=0;
		for(long long i=1;i<=h;i++){
			for(long long j=1;j<=n;j++){
				if(v[j]==0){
					if(a[c[i]][j]<minn){
						minn=a[c[i]][j];
						e=j;
					}
				}
			}
		}
		ans+=minn;
		v[e]=1;
		h++;
		c[h]=e;
		for(long long i=1;i<=n;i++){
			if(v[i]==1) o++;
		}
		if(o==n) break;
	}
	printf("%lld",ans);
	return 0;
}

