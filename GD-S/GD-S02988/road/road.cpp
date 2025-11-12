#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,s;
}a[1000006];
int n,m,k,fa[10014],s[15],d,id,x,f;
bool cmp(node x,node y){
	return x.s<y.s;
}
int root(int x){
	if(fa[x]==0)return x;
	return root(fa[x]);
}
void hb(int x,int y){
	x=root(x),y=root(y);
	fa[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].s);
	for(int i=1;i<=k;i++){
		cin>>f;
		d+=f;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[m+(i-1)*n+j].s);
			a[m+(i-1)*n+j].a=m+(i-1)*n+j,a[m+(i-1)*n+j].b=j;
		}
	}
	cout<<1;
	x=0,id=1;
	sort(a+1,a+m+n*k+1,cmp);
	while(x<n+k-1){
		if(root(a[id].a)!=root(a[id].b)){
			x++,d+=a[id].s;
			hb(a[id].a,a[id].b);
		}
		id++;
	}
	cout<<d;
	return 0;
} 
