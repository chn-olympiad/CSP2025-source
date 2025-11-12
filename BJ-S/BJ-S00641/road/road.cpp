#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e4+10;
const int M=2e6+10;
int n,m,k,c[15][N],f[N],ans;
struct node{
	int u,v,w;
} x[M];

int fi(int x){
	if (x==f[x])
		return x;
	return f[x]=fi(f[x]);
}
void me(int x,int y){
	f[fi(x)]=fi(y);
}
bool cmp(node a1,node a2){
	 if (a1.w<a2.w)
		return 1;
	return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long ans=0,cnt=0;
	for (int i=1;i<=n;i++)
		f[i]=i;
	for (int i=1;i<=m;i++)
		cin>>x[i].u>>x[i].v>>x[i].w;
	for (int i=1;i<=k;i++){
		for (int j=0;j<=n;j++){
			cin>>c[i][j];
			if (j==0)
				continue;
			if (c[i][j]==0){
				me(i,j),cnt++;
			}
			else{
				m++;
				x[m].u=i,x[m].v=j,x[m].w=c[i][j];
			}
		}
	}
	sort(x+1,x+m+1,cmp);
	//for (int i=1;i<=m;i++)
		//cout<<x[i].u<<" "<<x[i].v<<" "<<x[i].w<<'\n';
	
	for (int i=1;i<=m;i++){
		if (fi(x[i].u)!=fi(x[i].v)){
			me(x[i].u,x[i].v);
			ans+=x[i].w;
			cnt++;
		}
		if (cnt==n-1)
			break;
	}
	cout<<ans;
	return 0;
}