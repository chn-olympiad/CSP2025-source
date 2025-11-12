#include <cstdio>
#include <algorithm>
using namespace std;
int c[15];
int b[15][10005];
int coun[10005];
int cc[1005][1005];
struct rr{
	int aa,bb,cc;
}d[1000005];
bool cmp(rr x,rr y){
	return x.aa >y.aa;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int m1,m2,w;
		scanf("%d%d%d",&m1,&m2,&w);
		if(m1>m2){
			int tmp=m1;
			m1=m2;
			m2=tmp;
		}
		if(cc[m1][m2]){
			if(cc[m1][m2]>w){
				cc[m1][m2]=w;
				coun[m1]++;
				coun[m2]++;
			}
		}else{
			cc[m1][m2]=w;
			coun[m1]++;
			coun[m2]++;
		}
	}
	int flag=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		int o=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
			if(b[i][j]==0){
				o=j;
			}
		}
		if(o){
			for(int j=1;j<=n;j++){
				if(j==o) continue;
				int m1=o;
				int m2=j;
				if(m1>m2){
					int tmp=m1;
					m1=m2;
					m2=tmp;
				}
				if(cc[m1][m2]){
					if(cc[m1][m2]>b[i][j]){
						cc[m1][m2]=b[i][j];
						coun[m1]++;
						coun[m2]++;				
					}
				}else{
					cc[m1][m2]=b[i][j];
					coun[m1]++;
					coun[m2]++;				
				}
			}
		}else{
			flag=1;
		}
	}
	if(flag==0||k==0){
		int cnt=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum+=cc[i][j];	
				d[++cnt].aa =cc[i][j];	
				d[cnt].bb=i;
				d[cnt].cc=j;
			}
		}
		int pp=cnt-n+1;
		sort(d+1,d+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			if(pp&&coun[d[i].bb]>1&&coun[d[i].cc]>1){
				sum-=d[i].aa;
				pp--;
			}
		}
		printf("%lld",sum);
	}
	return 0;
} 
