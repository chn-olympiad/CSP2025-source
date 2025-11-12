#include<bits/stdc++.h>
using namespace std;
long long n,m,k,f[1000010],c[11][1000010],b[1000010],vis[110],ans=1e9;
void init(){
	for (long long i=1;i<=n+k;i++)f[i]=i;
}
long long find(long long x){
	if (f[x]==x){
		return x;
	}
	return f[x]=find(f[x]);
}
struct node{
	long long a,b,c;
};
node a[2000010],d[2000010];
bool cmp(node a,node b){
	return a.c<b.c;
}
void dfs(long long x,long long sum){
	if(x==k+1){
		long long res=0;
		init();
		long long now=m+1;
		for (long long i=1;i<=m;i++)d[i].a=a[i].a,d[i].b=a[i].b,d[i].c=a[i].c;
		for (long long i=1;i<=k;i++){
			if (vis[i]){
				res+=b[i];
				for (long long j=1;j<=n;j++){
					d[now].a=n+i,d[now].b=j,d[now].c=c[i][j];
					now++;
				}
			}
		//	cout <<vis[i];
		}
	//	cout <<endl<<res<<endl;
		sort(d+1,d+now,cmp);
		for(long long i=1;i<=now;i++){
			if (find(d[i].a)!=find(d[i].b)){
				f[find(d[i].a)]=find(d[i].b);
				res+=d[i].c;
	//			cout <<d[i].a<<" "<<d[i].b<<endl;;
			}
		}
	//	cout <<endl;
	//	cout <<res<<" "<<sum<<endl;
		ans=min(ans,res);
		return ;
	}
	
	vis[x]=0;
	dfs(x+1,sum);
	vis[x]=1;
	dfs(x+1,sum+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for (long long i=1;i<=m;i++){
		cin >>a[i].a>>a[i].b>>a[i].c;
	}
	sort(a+1,a+1+m,cmp);
	long long sum=0;
	for (long long i=1;i<=k;i++){
		cin >>b[i];
		for (long long j=1;j<=n;j++){
			cin >>c[i][j];
			sum+=c[i][j];
		}
	}
/*	if (sum==0&&k!=0){
		cout <<0;
		return 0;
	}*/
	if (k==0){
		long long ans=0;
		for(long long i=1;i<=m;i++){
			if (find(a[i].a)!=find(a[i].b)){
				f[find(a[i].a)]=find(a[i].b);
				ans+=a[i].c;
			}
		}
		cout <<ans;
		return 0;
	}
	dfs(1,0);
	cout <<ans;
	return 0;
}
