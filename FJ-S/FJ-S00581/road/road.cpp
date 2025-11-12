#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m,k,fa[N],tot,flag[N],c[15],wil[15][N],cnt;
struct Point{
	int u,v,w;
}point[N];
long long find(int x){
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
void unionn(long long a,long long b){
	long long aa=find(a),bb=find(b);
	fa[aa/1ll]=bb;
	return;
}
bool cmp(Point a,Point b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt=m;
	for(int i=1;i<=m;i++){
		cin>>point[i].u>>point[i].v>>point[i].w;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++)cin>>wil[i][j];
//		for(int j=1;j<=m;j++){
//			point[j].w=min(point[j].w,wil[i][point[j].u]+wil[i][point[j].v]+c[i]);
//		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int f=1;f<=n;f++){
				if(f==j)continue;
				point[++cnt].u=j;
				point[cnt].v=f;
				point[cnt].w=wil[i][j]+wil[i][f]+c[i];
			}
		}
	}
	sort(point+1,point+1+cnt,cmp);
	int t=0;
	for(int i=1;i<=cnt;i++){
		if(find(point[i].u)!=find(point[i].v)){
			unionn(point[i].u,point[i].v);
			flag[i]=1;
			t++;
			tot+=point[i].w;
		}
		if(t==n-1)break;
	}
	cout<<tot;
	return 0;
}
