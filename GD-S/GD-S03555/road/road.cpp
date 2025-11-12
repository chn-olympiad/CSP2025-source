#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11][100001],fa[100011],p[11],maxx,cnt[1001][1001],cnt1;
struct node{
	int from,to,dis;
}a[2000001];
bool cmp(node x,node y){
	return x.dis<y.dis;
}
inline void init(){
	for(int i=1;i<=n+k;i++)fa[i]=i;
}
inline int find(int x){
	if(x!=fa[x])return fa[x]=find(fa[x]);
	return x;
}
inline long long kruscal(int x,int y){
	init();
	for(int i=1;i<=c[x][0];i++){
		a[m+i].from=n+x;
		if(i%n!=0)a[m+i].to=i%n;
		else a[m+i].to=n;
		a[m+i].dis=c[x][i];
	}
	for(int i=1;i<=c[y][0];i++){
		a[m+i+c[x][0]].from=n+y;
		if(i%n!=0)a[m+i+c[x][0]].to=i%n;
		else a[m+i+c[x][0]].to=n;
		a[m+i+c[x][0]].dis=c[y][i];		
	}
	sort(a+1,a+1+m+c[x][0]+c[y][0],cmp);
	long long sum=0;
	for(int i=1;i<=m+c[x][0]+c[y][0];i++){
		int from=a[i].from,to=a[i].to,dis=a[i].dis;
		int r1=find(from);
		int r2=find(to);
		if(r1!=r2){
			sum+=dis;
			fa[r1]=r2;
		}
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].from,&a[i].to,&a[i].dis);
	if(k==0){
		init();
		sort(a+1,a+1+m,cmp);
		long long sum=0;
		for(int i=1;i<=m;i++){
			int r1=find(a[i].from);
			int r2=find(a[i].to);
			if(r1!=r2){
				sum+=a[i].dis;
				fa[r1]=r2;
				cnt1++;
			}
			if(cnt1==n-1)break;
		}		
		printf("%lld",sum);
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&p[i]);
		maxx=max(maxx,p[i]);
		c[i][0]=n;
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	if(maxx==0 && n<=1000){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				cnt[j][k]=c[1][j]+c[1][k];
			}
		}
		for(int i=2;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					cnt[j][k]=min(cnt[j][k],c[i][j]+c[i][k]);
				}
			}
		}
		int id=m;
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				a[++id]={j,k,cnt[j][k]};
			}
		}
		init();
		sort(a+1,a+1+id,cmp);
		long long sum=0;
		for(int i=1;i<=id;i++){
			int r1=find(a[i].from);
			int r2=find(a[i].to);
			if(r1!=r2){
				sum+=a[i].dis;
				fa[r1]=r2;
				cnt1++;
			}
			if(cnt1==n-1)break;
		}		
		printf("%lld",sum);
		return 0;
	}
	long long minx=kruscal(0,0);
	int minid=0;
	for(int i=1;i<=k;i++){
		int num=kruscal(i,minid)+p[i];
		for(int j=1;j<=c[minid][0];j++){
			c[i][c[i][0]+j]=c[minid][j];
		}
		c[i][0]+=c[minid][0];
		if(minx>num){
			minx=num;
			minid=i;
		}
	}
	printf("%lld",minx);
	return 0;
} 
