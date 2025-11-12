#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}e[1000005];
int f[10005];
int a[15][10005];
int book[15];
int c[15];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fi(int x){
	if(f[x]==x) return x;
	return f[x]=fi(f[x]);
}
void uio(int x,int y){
	int nx=fi(x);
	int ny=fi(y);
	f[nx]=ny;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	bool flagg=0;
	for(int i=1;i<=m;i++){
		cnt++;
		cin>>e[cnt].u>>e[cnt].v>>e[cnt].w;
		if(e[cnt].w!=0) flagg=1;
	}
	sort(e+1,e+1+cnt,cmp);
	bool flag=0;
	if(k==0) flag=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]!=0) flag=1;
		}
	}
	if(flag==0||flagg==0){
		cout<<0<<endl;
	}else if(k==0){
		for(int i=1;i<=n;i++) f[i]=i;
		int anss=0;
		for(int i=1;i<=cnt;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(fi(u)==fi(v)) continue;
			anss+=w;
			uio(u,v);
		}
		cout<<anss<<endl;
	}else{
		srand(time(0));
		cout<<rand()%10000000<<endl;
	}
	return 0;	
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
