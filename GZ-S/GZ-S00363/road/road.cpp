//GZ-S00363 毕节梁才学校 罗悦辉
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m,k;

struct OP {
	int x,y;
	LL z;
} e[2000000+10];

bool cmp(OP a,OP b) {
	return a.z<b.z;
}

int q[10000+10];
int find(int x) {
	if(x!=q[x]) q[x]=find(q[x]);
	return q[x];
}

LL ans,zz;
bool f=true;
int xx,yy,gx,gy;
vector<int> u[20],v[20];

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);

	for(int i=1; i<=n+k; i++) q[i]=i;

	for(int i=1; i<=m; i++) {
		scanf("%d%d%lld",&xx,&yy,&zz);
		e[i]=(OP) {
			xx,yy,zz
		};
	}

	if(k==0) {

		sort(e+1,e+m+1,cmp);

		for(int i=1; i<=m; i++) {
			xx=e[i].x,yy=e[i].y,zz=e[i].z;
			gx=find(xx),gy=find(yy);
			if(gx==gy) continue;
			else ans+=zz;
			q[gx]=gy;
		}

		printf("%lld",ans);
		return 0;

	}

		for(int i=1;i<=k;i++){
			scanf("%d",&xx);
			if(xx!=0) f=false;
			for(int j=1;j<=n;j++){
				scanf("%lld",&zz);
				e[m+(i-1)*n+j]=(OP){j,n+i,zz};
			}
		}
		
		if(f){
			
			sort(e+1,e+(m+n*k)+1,cmp);
			
			for(int i=1;i<=m+n*k;i++){
				xx=e[i].x,yy=e[i].y,zz=e[i].z;
				gx=find(xx),gy=find(yy);
				if(gx==gy) continue;
				ans+=zz;
				q[gx]=gy;
				if(xx>n) u[xx-n].push_back(yy),v[xx-n].push_back(zz);
				else if(yy>n) u[yy-n].push_back(xx),v[yy-n].push_back(zz);
			}
			
			for(int i=1;i<=k;i++){
				if((int)u[i].size()==1) ans-=v[i][0];
			}
			
			printf("%lld",ans);
			return 0;
			
		}
		
	return 0;
}
