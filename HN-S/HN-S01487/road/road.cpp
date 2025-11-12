#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=2e6+10;
long long c[20],a[20][N];
int fa[N];
struct node{
	long long v;
	int x,y;
}b[M];
bool cmp(node a,node b){
	return a.v<b.v;
}
int get(int x){
	if(x==fa[x]){
		return x;
	} 
	return fa[x]=get(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,tot=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int xx,yy,z;
		cin>>xx>>yy>>z;
		b[i].v=z;
		b[i].x=xx;
		b[i].y=yy;
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(b+1,b+m+1,cmp);
	long long ans=0,sum=0;
	for(int i=1;i<=m;i++){
		if(get(b[i].x)!=get(b[i].y)){
			fa[get(b[i].x)]=get(b[i].y);
			sum+=b[i].v;
			//cout<<b2[i].v<<endl;
		}
	}
	ans=sum;
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<1<<k;i++){
		tot=m;
		for(int j=1;j<=n+2*k;j++){
			fa[j]=j;
		}
		for(int j=0;j<k;j++){
			if((i&(1<<j))!=0){
				b[++tot].v=c[j];
				b[tot].x=n+j+1;
				b[tot].y=n+k+j+1;
				for(int ii=1;ii<=n;ii++){
					b[++tot].v=a[j][ii];
					b[tot].x=n+j+1;
					b[tot].y=ii;
				}
			}
		}
		sum=0;
		sort(b+1,b+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			if(get(b[i].x)!=get(b[i].y)){
				fa[get(b[i].x)]=get(b[i].y);
				sum+=b[i].v;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
