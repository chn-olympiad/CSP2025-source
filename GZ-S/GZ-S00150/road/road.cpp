//GZ-S00150 毕节梁才学校 张哲铭
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
int p[200000+2000000+10]; 
int n,m,k,x;
int find(int x){
	if(p[x]!=x){
		int zu=find(p[x]);
		p[x]=zu;
	}
	return p[x];
}
struct E{
	int x;
	int y;
	int z;
}e[2000000+200000+10];
bool cmp(E a,E b){
	return a.z<b.z;
}
bool v[200000+10];//是否花费 
LL ans;
int cnt;
int num;
bool kruscal(){
	sort(e+1,e+m+k*n+1,cmp);
	for(int i=1;i<=m+k*n;i++){
		int x=e[i].x;
		int y=e[i].y;
		int z=e[i].z;
		int gx=find(x);
		int gy=find(y);
		if(gx!=gy){
			p[gx]=gy;
			cnt++;
			ans+=z;
		}
	}
	return cnt<n-1;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n*2+m*2+k*n*2;i++)p[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[++num]=(E){x,y,z};
		e[++num]=(E){y,x,z};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		for(int j=1;j<=n;j++){
			int z;
			scanf("%d",&z);
			e[++num]=(E){0,j,z+x};
			e[++num]=(E){j,0,z+x};
		}
	}
	kruscal();
	printf("%lld\n",ans);
	return 0;
}
