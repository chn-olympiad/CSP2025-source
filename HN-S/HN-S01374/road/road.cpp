#include<bits/stdc++.h>

using namespace std;
//Ren5Jie4Di4Ling5%
int n,m,k,c[110],d[110][1010],f[1000010],mi=0x3f3f3f3f;
int fi(int x){
	
	if(f[x]==x)return x;
	return f[x]=fi(f[x]);
}
struct P{
	long long x,y,z;
}a[1500000],e[1500000];
bool cmp(P a,P b){
	return a.z<b.z;
}
void dfs(long long u,long long ss){
	if(u==k+1){
		for(long long i=1;i<=m;i++)e[i]=a[i];
		for(long long i=1;i<=n;i++)f[i]=i;
		long long su=0;
		sort(a+1,a+1+m,cmp);
		for(long long i=1;i<=m;i++){
			long long x=a[i].x,y=a[i].y;
			long long xx=fi(x),yy=fi(y);
			if(xx==yy)continue;
//				cout<<x<<' '<<y<<' '<<a[i].z<<"\n";
			su+=a[i].z;
			f[xx]=yy;
		}
		mi=min(mi,su+ss);
		for(long long i=1;i<=m;i++)a[i]=e[i];
//		cout<<su+ss<<"\n";
		return;
	}
	dfs(u+1,ss);
	for(long long j=1;j<=n;j++){
		a[++m]={u,j,d[u][j]};
	}
	dfs(u+1,ss+c[u]);
	m-=n;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
	long long ff=1;
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		ff&=(c[i]==0);
		for(long long j=1;j<=n;j++)cin>>d[i][j];
	}
	
	if(k==0){
		for(long long i=1;i<=n;i++)f[i]=i;
		long long su=0;
		sort(a+1,a+1+m,cmp);
		for(long long i=1;i<=m;i++){
			long long x=a[i].x,y=a[i].y;
			long long xx=fi(x),yy=fi(y);
			if(xx==yy)continue;
			su+=a[i].z;
			f[xx]=yy;
		}
		cout<<su;
		return 0;
	}
	if(ff){
		for(long long i=1;i<=k;i++){
			for(long long j=1;j<=n;j++){
				a[++m]={i,j,d[i][j]};
			}
		}
			for(long long i=1;i<=n;i++)f[i]=i;
		long long su=0;
		sort(a+1,a+1+m,cmp);
		
		for(long long i=1;i<=m;i++){
			long long x=a[i].x,y=a[i].y;
			long long xx=fi(x),yy=fi(y);
			if(xx==yy)continue;
			su+=a[i].z;
		
			f[xx]=yy;
		}
		cout<<su;
		return 0;
	dfs(1,0);
	cout<<mi;
	return 0;
} /*
4 6 0
1 2 1
1 3 1
2 3 2
1 4 2
2 4 1
3 4 1

*/
