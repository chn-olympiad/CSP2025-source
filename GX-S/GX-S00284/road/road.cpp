#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
struct node{
	int to,ne,da;
};
node e[200033];
int n,m,k;
int fa[10033];
int find(int a){
	if(fa[a]==a){
		return a;
	}
	else{
		return fa[a]=find(fa[a]);
	}
}void add(int x,int y,int z){
	cnt++;
	e[cnt].ne=x;
	e[cnt].to=y;
	e[cnt].da=z;
	return;
}
void hb(int x,int y){
	x=find(x);
	y=find(y);
	fa[y]=x;
	return;
}
bool cmp(node i,node j){
	return i.da<j.da;
}
int ku(){
	int i,sum=1;
	long long anss=0;
	sort(e+1,e+1+cnt,cmp);
	for(i=1;i<=cnt;i++){
		int x,y;
		x=e[i].ne;
		y=e[i].to;
		if(find(x)!=find(y)){
			hb(x,y);
			sum=sum+1;
			anss=anss+e[i].da;
		}
		if(sum==(k+n)){
			break;
		}
	}
	return anss;
}
int main(){
	int i,j;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//cin>>n>>m>>k;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		//cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(i=1;i<=k;i++){
		int x;
	//	cin>>x;
		scanf("%d",&x);
		x=n+i;
		for(j=1;j<=n;j++){
			int z;
			//cin>>z;
			scanf("%d",&z);
			add(x,j,z);
			add(j,x,z);
		}
	}
	for(i=1;i<=n+k;i++){
		fa[i]=i;
	}
	long long anss;
	anss=ku();
	printf("%lld",anss);
	//cout<<anss;
	return 0;
}
