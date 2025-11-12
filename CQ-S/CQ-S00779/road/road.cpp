#include<bits/stdc++.h>
using namespace std;
const int M=1e6+6,N=1e4+4;
int n,m,f[N],k,cnt;
long long sum;
struct node{
	int f,t;
	long long v;
}a[M+N*N];
int fin(int x){
	if(f[x]==x)return x;
	else return f[x]=fin(f[x]);
}
bool cmp(node x,node y){
	return x.v<y.v;
}
void b(){
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int ff=a[i].f,t=a[i].t;
		if(fin(ff)!=fin(t)){
			ff=fin(ff),t=fin(t);
			f[t]=ff;
			ans++;
			sum+=a[i].v;
			if(ans==n-1){
				cout<<sum;
				return ;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	cnt=m;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		long long x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(x>y) a[i].f=y,a[i].t=x;
		else a[i].f=x,a[i].t=y;
		a[i].v=z;
	}
	for(int i=1;i<=k;i++){
		long long q,w[N];
		scanf("%d",&q);
		for(int j=1;j<=n;j++)scanf("%d",&w[j]);
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				a[++cnt].f=l;
				a[cnt].t=r;
				a[cnt].v=q+w[l]+w[r];
			}
		}
	}
	sort(a+1,a+1+cnt,cmp);
	b();
	return 0;
} 
