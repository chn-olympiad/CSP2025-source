#include<iostream>
#include<algorithm>
const int N=10010,M=1000010;
int n,m,k,fx,fy,cnt,c[20],f[N+20],b[20][N];
unsigned long long ans;
struct node{
	int x,y,l;
}a[M+N*10];
bool cmp(node a,node b){
	return a.l<b.l;
}
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		std::cin>>a[i].x>>a[i].y>>a[i].l;
	}
	for(int i=1;i<=k;i++){
		std::cin>>c[i];
		n++;
		for(int j=1;j<=n-i;j++){
			std::cin>>b[i][j];
			if(c[i]==0){
				a[++m].x=n,a[m].y=j,a[m].l=b[i][j];
			}
		}
	}
	std::sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		fx=find(a[i].x),fy=find(a[i].y);
		if(fx==fy){
			continue;
		}
		f[fx]=fy,ans+=a[i].l,cnt++;
		if(cnt==n-1){
			break;
		}
	}
	std::cout<<ans;
	return 0;
}
/*
A:c[j]=0
O((m+nk)log(m+nk))
n=1e4 m=1e6 k=10 (1e6+1e5)log(1e6+1e5) 2e7
1e6+1e4 640ms
48
*/
