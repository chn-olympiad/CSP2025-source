#include<bits/stdc++.h>
using namespace std;

int n,m,k,u,v,w;
int c[15][1015];
struct city{
	int u,v,w;
}lx[1000015]; 
long long cnt;

bool cmp(city x,city y){
	return x.w>y.w;
}

int main(){
	freopen("road,in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>lx[i].u>>lx[i].v>>lx[i].w,cnt+=lx[i].w;
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			cin>>c[i][j];
	sort(lx+1,lx+1+m,cmp);
	int x=m,p=0;
	while(x>n-1)
		cnt-=lx[++p].w,x--;
	cout<<cnt;
	return 0;
}
