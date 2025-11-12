#include<bits/stdc++.h>
using namespace std;

const int N=1000010;
struct Node {
	int to,next,len,tr=1;
}a[N*2];
long long pre[N],k=1,d[N],l[N],ci[N];
bool f[N];
int n,m,kk,x,y,z;
void add(int v,int u,int le) {
	a[k].to=v;
	a[k].len=le;
	a[k].next=pre[u];
	pre[u]=k;
	k++;
}
bool fun(Node x,Node y) {
	return x.len<y.len;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>kk;
	for(int i=1;i<=m;i++) {
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=kk;i++) {
		cin>>x;
		for(int j=1;j<=n;j++) {
			cin>>y;
			add(n+i,j,y);
			add(j,n+i,y);
		} 
	}
	sort(a+1,a+n+1,fun);
	long long cnt=0;
	for(int i=1;i<n;i++) {
		cnt+=a[pre[i]].len;
	}
	cout<<cnt;
//	memset(f,0,sizeof(f));
//	dfs(0)
//	for(int i=1;i<=n+kk;i++) {
//		cout<<d[i]<<' ';
//	}
	//Ren5Jie4Di4Ling5%
	return 0; 
}

