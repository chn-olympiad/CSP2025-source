#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,w;
}g[2000005];
int f[20005];
int findfa(int x){
	if(f[x]==x)return x;
	else return f[x];
}
bool cmp(node x,node y){
	return x.w<y.w;
}
int a[10005];
int main(){
	freopen("road.in","r",stdin);
  	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>g[i].x>>g[i].y>>g[i].w;
	}
	sort(g+1,g+m+1,cmp);
	int num=1;
	int ans=0;
	for(int i=1;i<=m;i++){
		int x,y,w;
		x=g[i].x,y=g[i].y,w=g[i].w;
		int x1=findfa(x),y1=findfa(y);
		if(x1==y1)continue;
		f[y1]=x1;
		num++;
		ans+=w;
		if(num==n)break;
	}
	if(k==0){
		cout<<ans;
		return 0;	
	}
	int n1=n;
	for(int i=1;i<=k;i++){
		n1++;
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a[j];
			m++;
			g[m].x=j,g[m].y=n1,g[m].w=a[j];
		}
	}
	n=n1;
	for(int i=1;i<=n;i++)f[i]=i;
	sort(g+1,g+m+1,cmp);
	num=1;
	ans=0;
	for(int i=1;i<=m;i++){
		int x,y,w;
		x=g[i].x,y=g[i].y,w=g[i].w;
		int x1=findfa(x),y1=findfa(y);
		if(x1==y1)continue;
		f[y1]=x1;
		num++;
		ans+=w;
		if(num==n)break;
	}
	cout<<ans;
	return 0;
}

