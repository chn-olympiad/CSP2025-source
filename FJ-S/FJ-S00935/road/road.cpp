#include<bits/stdc++.h>
using namespace std;

const int N=10025,inf=1e9;
int n,m,k,a[N][15],c[15],minn=inf;
vector <int> u1[N],u2[N];

int prim(int t){
	int np=n,sum=0;vector <int> v1[N],v2[N];
	for(int i=1;i<=n;i++) for(int j=0;j<u1[i].size();j++) v1[i].push_back(u1[i][j]),v2[i].push_back(u2[i][j]);
	for(int i=0;i<k;i++) if((1<<i)&t){
		sum+=c[i];np++;for(int j=1;j<=n;j++) v1[np].push_back(j),v1[j].push_back(np),v2[np].push_back(a[j][i]),v2[j].push_back(a[j][i]);
	}
	bool s[N];int ans[N];for(int i=2;i<=np;i++) ans[i]=inf;ans[0]=inf;for(int i=1;i<=np;i++) s[i]=0;ans[1]=0;
	while(true){
		int x=0;for(int i=1;i<=np;i++) if((!s[i])&&ans[i]<ans[x]) x=i;if(x==0) break;
		s[x]=1;for(int i=0;i<v1[x].size();i++) ans[v1[x][i]]=min(ans[v1[x][i]],v2[x][i]);
	}
	for(int i=1;i<=np;i++) sum+=ans[i];return sum;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int x,y,z;scanf("%d%d%d",&x,&y,&z);
		u1[x].push_back(y);u1[y].push_back(x);
		u2[x].push_back(z);u2[y].push_back(z);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[j][i]);
	}
	for(int i=0;i<(1<<k);i++) minn=min(minn,prim(i));
	printf("%d",minn);
	return 0;
}
