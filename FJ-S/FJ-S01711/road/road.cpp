#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct shu{
	int u,v,w,bj;
}a[2000005];
int n,m,k,cnt;
ll sum,ans;
int f[10005];
bool bj[15],tsxz;
int c[15][100005];

int find(int x){
	if(f[x]=x){
		return f[x];
	}
	else{
		f[x]=find(f[x]);
		return find(f[x]);
	}
}

bool hb(int x,int y){
	int u=find(x);
	int v=find(y);
	if(u==v){
		return false;
	}
	else{
		f[u]=f[v];
		return true;
	}
}

bool cmp(shu x,shu y){
	return x.w<y.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt=m;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]!=0){
				tsxz=1;
			}
		}
	}
	if(tsxz==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=j+1;l<=n;l++){
				a[++cnt].u=j;
				a[cnt].v=l;
				a[cnt].w=c[i][j]+c[i][l]+c[i][0];
				a[cnt].bj=i;
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(hb(a[i].u,a[i].v)){
			if(a[i].bj!=0){
				if(bj[a[i].bj]==0){
					ans+=a[i].w;
					bj[a[i].bj]=true;
				}
				else{
					ans+=a[i].w-c[a[i].bj][0];
				}
			}
			else{
				ans+=a[i].w;
			}
			if(++sum==n-1){
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 

