#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+6,N=1e4+4;
struct Node{
	int dj,u,v;
} a[M],tx[1<<11][N],t[N],sum[N*4];
int n,m,k,fa[N*2],c[15],tot=0,an[1<<11],ans,q=0,vis[N*2];
bool p=1;
bool cmp(Node x,Node y){
	return x.dj<y.dj;
}
int lowbit(int n){
	return n&(-n);
}
int find(int u){
	if(u==fa[u]){
		return u;
	}
	return fa[u]=find(fa[u]);
}
void un(int a,int b){
	int u=find(a),v=find(b);
	if(u==v){
		return ;
	}
	fa[u]=v;
}
void hb(int c1,int c2,int c){
	int xb1=1,xb2=1;
	for(int i=1;i<=n;i++){
		if(tx[c1][xb1].dj<tx[c2][xb2].dj && xb1<=n){
			tx[c][i]=tx[c1][xb1];
			xb1++;
		}
		else if(xb2<=n){
			tx[c][i]=tx[c2][xb2];
			xb2++;
		}
		else {
			tx[c][i]=tx[c1][xb1];
			xb1++;
		}
	}
}
int ws(int n){
	int s=0;
	while(n){
		n-=lowbit(n);
		s++;
	}
	return s;
}
int tj(int c){
	int xb1=1,xb2=1,qh=0,kk=ws(c),no=1;
	for(int i=1;i<=n*2;i++){
		if(t[xb1].dj<tx[c][xb2].dj && xb1<=n){
			sum[i]=t[xb1];
			xb1++;
		}
		else if(xb2<=n){
			sum[i]=tx[c][xb2];
			xb2++;
		}
		else {
			sum[i]=t[xb1];
			xb1++;
		}
	}
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	int xb=1;
	while(no<=n+kk-1 && xb<=n*2){
		if(sum[xb].u==sum[xb].v){
			xb++;
			continue;
		}
		if(find(sum[xb].u) != find(sum[xb].v)){
			un(sum[xb].u,sum[xb].v);
			vis[sum[xb].u]=1;
			vis[sum[xb].v]=1;
			if(sum[xb].u>n){
				vis[sum[xb].u-n]=1;
			}
			no++;
			qh+=sum[xb].dj;
		}
		xb++;
	}
	return qh;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].dj;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			p=0;
		}
		for(int j=1;j<=n;j++){
			cin>>tx[1<<(i-1)][j].dj;
			tx[1<<(i-1)][j].u=n+k;
			tx[1<<(i-1)][j].v=j;
		}
		sort(tx[1<<(i-1)]+1,tx[1<<(i-1)]+1+n,cmp);
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(tot==n-1){
			break;
		}
		if(find(a[i].u) != find(a[i].v)){
			t[++tot]=a[i];
			q+=a[i].dj;
			un(a[i].u,a[i].v);
		}
    }
	for(int i=1;i<(1<<k);i++){
		int num=0;
		memset(vis,0,sizeof(vis));
		if(i^lowbit(i)){
			hb(lowbit(i),i^lowbit(i),i);
		}
		an[i]=tj(i);
		for(int j=0;j<k;j++){
			if((i>>(j))&1){
				num+=c[j+1];
				if(!vis[n+j+1]){
					//cout<<1;
					num+=tx[(1<<j)][1].dj;
				}
			}
		}
		an[i]+=num;
	}
	ans=q;
	for(int i=1;i<(1<<k);i++){
		ans=min(ans,an[i]);
	}
	cout<<q;
	return 0;
}