#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[1001],cnt,r,ans;
struct node{
	int x,y,z;
}a[101000001],l[10001];
int cc[1001],s[1001][1001],c[1001],v[1001];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
bool cmp(node a,node b){
	return a.z<b.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i][j]=pow(2,30);
		}
		s[i][i]=0;
		f[i]=i;
	}
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[++cnt]={u,v,w};
	}
	
	if(k==0){
		sort(a+1,a+1+cnt,cmp);
		for(int i=1,x,y;i<=cnt;i++){
			x=find(a[i].x),y=find(a[i].y);
			if(x!=y){
				f[x]=y;
				ans+=a[i].z;
				r++;
//				s[a[i].x][a[i].y]=s[a[i].y][a[i].x]=a[i].z;
			}
			if(r==n-1)break;
		}
		cout<<ans;
	}	
	else{
		for(int i=1;i<=k;i++){
			scanf("%d",&cc[i]);
			for(int j=1;j<=n;j++){
				scanf("%d",&c[j]);
				for(int ii=1;ii<j;ii++)
					a[++cnt]={j,ii,c[j]+c[ii]};
			}
		}
		sort(a+1,a+1+cnt,cmp);
		for(int i=1,x,y;i<=cnt;i++){
			x=find(a[i].x),y=find(a[i].y);
			if(x!=y){
				f[x]=y;
				ans+=a[i].z;
				r++;
//				cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<'\n';
//				s[a[i].x][a[i].y]=s[a[i].y][a[i].x]=a[i].z;
			}
			if(r==n-1)break;
		}
		cout<<ans;
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
