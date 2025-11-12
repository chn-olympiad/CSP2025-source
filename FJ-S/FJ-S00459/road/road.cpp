#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10005
#define M 1000005
struct jgt{
	int u,v,w;
};
int n,m,k,ans,fl;
int f[N];
int a[N][N];
jgt b[M];
int c[N];
bool cmp(jgt x,jgt y){
	return x.w<y.w;
}
void hbb(int x,int y){
	for(int i=1;i<=n;i++){
		if(a[y][i]==1){
			a[x][i]=1;
			a[y][i]=0;
			f[i]=x;
		}
	}
	a[x][0]+=a[y][0]+1;
	a[y][0]=0;
	f[y]=x;
}
void hba(int x,int y){
	if(a[x][0]==a[y][0]||a[x][0]>a[y][0]){
		hbb(x,y);
	}
	else if(a[x][0]<a[y][0]){
		hbb(y,x);
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	for(int i=1;i<=k;i++){
		fl=0;
		for(int j=0;j<=n;j++){
			cin>>c[j];
		}
		if(c[0]==0){
			for(int j=1;j<=n;j++){
				if(c[j]==0&&fl==0){
					fl=j;
				}
				else if(c[j]==0&&fl!=0){
					if(f[j]==f[fl]) continue;
					hba(f[j],f[fl]);
				}
			}
		}
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(f[b[i].u]==f[b[i].v]) continue;
		ans+=b[i].w;
		hba(f[b[i].v],f[b[i].u]);
	}
	cout<<ans;
	return 0;
}
