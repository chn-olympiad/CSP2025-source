#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[11000],pp[11000];
long long c[15],g[10100][10100],cnt,minn;
struct code{
	long long z;
	int x,y;
}edge[1200000],eg[120000];
bool cmp(const code &a,const code &b){
	return a.z<b.z;
}
int find(int x){
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}
bool b;
void dfs(int x,int t,long long s){
	if(x==k){
		if(t==0) return;
		int cc=t*n;
		long long ss=s;
		sort(eg+1,eg+cc+1,cmp);
		for(int i=1;i<=n+k;i++)
			f[i]=i;
		int kk=0,i=1,j=1;
		while(kk<n+k&&i<=m&&j<=cc){
			int fa=find(edge[i].x),fb=find(edge[i].y);
			if(fa==fb){
				i++;
				continue;
			}
			int fa2=find(eg[j].x),fb2=find(eg[j].y);
			if(fa2==fb2){
				j++;
				continue;
			}
			if(edge[i].z>eg[j].z){
				ss+=eg[j].z;
				j++;
				f[fa2]=fb2;
			}
			else {
				ss+=edge[i].z;
				f[fa]=fb;
				i++;
			}
			kk++;
			if(ss>=minn) return;
		}
		minn=min(minn,ss);
		return;
	}
	dfs(x+1,t,s);
	for(int i=1;i<=n;i++){
		eg[i+t*n].x=n+x;
		eg[i+t*n].y=i;
		eg[i+n*t].z=g[n+x][i];
	}
	dfs(x+1,t+1,s+c[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&edge[i].x,&edge[i].y,&edge[i].z);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0) b=1;
		bool bb=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&g[i+n][j]);
			if(g[i+n][j]==0) bb=1;
		}
		if(!bb) b=1;
	}
	if(!b){
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++){
				edge[m+(i-1)*n+j].x=i+n;
				edge[m+(i-1)*n+j].y=j;
				edge[m+(i-1)*n+j].z=g[i+n][j];
			}
		sort(edge+1,edge+m+k*n+1,cmp);
		int nk=0;
		long long sss=0;
		for(int i=1;i<=n+k;i++)
			f[i]=i;
		for(int i=1;i<=m+n*k;i++){
			int fa=find(edge[i].x),fb=find(edge[i].y);
			if(fa!=fb){
				sss+=edge[i].z;
				f[fa]=fb;
				nk++;
				if(nk==n+k-1){
					break;
				}
			}
		}
		printf("%lld\n",sss);
		return 0;
	}
	int kkk=0;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fa=find(edge[i].x),fb=find(edge[i].y);
		if(fa!=fb){
			f[fa]=fb;
			minn+=edge[i].z;
			kkk++;
			if(kkk==n-1) break;
		}
	}	
	dfs(1,0,0);
	printf("%lld\n",minn);
	return 0;
}
