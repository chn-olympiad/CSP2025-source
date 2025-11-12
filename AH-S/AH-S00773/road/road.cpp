#include<bits/stdc++.h>
using namespace std;
long long n,m,k,v[1005],f[1005],vis[1005][1005],ans;
struct node{
	long long x,y,c;
}a[1000005];
long long cmp(node x,node y){
	return x.c<y.c;
}
long long find(long long x){
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}
void add(long long x,long long y){
	long long a=find(x),b=find(y);
	f[b]=a;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	memset(vis,0x3f,sizeof(vis));
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].c;
		vis[a[i].x][a[i].y]=a[i].c;
		vis[a[i].y][a[i].x]=a[i].c;
	}
	for(int i=1;i<=k;i++){
		int cc;
		cin>>cc;
		for(int j=1;j<=n;j++){
			cin>>v[j];
		}
		for(int j=1;j<n;j++){
			for(int kk=j+1;kk<=n;kk++){
				if(v[j]+v[kk]<vis[j][kk]){
					vis[j][kk]=v[j]+v[kk];
					vis[kk][j]=vis[j][kk];
				}
			}
		}
	}
	m=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(vis[i][j]<=1e9){
				a[++m].x=i;
				a[m].y=j;
				a[m].c=vis[i][j];
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int t=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].x)!=find(a[i].y)){
			add(a[i].x,a[i].y);
			ans+=a[i].c;
			t++;
		}
		if(t==n-1){
			cout<<ans;
			return 0;
		}
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
