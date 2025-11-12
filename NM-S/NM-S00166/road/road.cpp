#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[1000010];
struct node{
	int b;
	int c;
	bool d;
}f[10010];
bool cmp(node x1,node y1){
	return (x1.b+x1.c)<(y1.b+y1.c);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		a[i]=w;
	}
	for (int i=1;i<=n+1;i++){
		cin>>f[i].b;
	}
	for (int i=1;i<=n+1;i++){
		cin>>f[i].c;
	}
	sort(a+1,a+1+m);
	sort(f+1,f+n+2,cmp);
	int ans=0;
	for (int i=1;i<=k;i++){
		ans+=a[i];
	}
 	f[1].d=1;
 	ans+=f[1].b;
 	ans+=f[1].c;
 	int minn=0x3f3f3f3f;
	for (int i=1;i<=n+1;i++){
		if (f[i].c<minn&&f[i].d==0){
			minn=f[i].c;
		}
	}
	ans+=minn;
	cout<<ans;
	return 0;
}
