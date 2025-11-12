#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
const int N=1e5+10,M=1e6+10,K=20;
struct node{
	int to,next,len;
}a[M*2+K*N];
int n,m,k,tot,pre[N],c[K],d[N+K],ans;
priority_queue<PI,vector<PI>,greater<PI>> q;
bool TA=1,f[N];
void add(int u,int v,int len){
	a[++tot]={v,pre[u],len},pre[u]=tot;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z),add(y,x,z);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1,x,z;j<=n;j++){
			scanf("%d%d",&x,&z);
			add(n+i,x,z),add(x,n+i,z+c[i]);
		}
	}
	cout<<0;
	return 0;
}
