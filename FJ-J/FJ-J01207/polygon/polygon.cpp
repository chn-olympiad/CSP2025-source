#include<bits/stdc++.h>
using namespace std;
const int mod= 998244353;
long long n;
struct node {
	int num,id;
} a[5005];
struct edge {
	int id,sum,dis,mx;
} bmp;
bool cmp(node x,node y) {
	if(x.num==y.num)return x.id<y.id;
	return x.num<y.num;
}
int fst[10005],to[10005],nxt[10005],p;
void add(int u,int v) {
	to[++p]=v;
	nxt[p]=fst[u];
	fst[u]=p;
}
queue<edge>q;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n-1; i++) {
		for(int j=i+1; j<=n; j++) {
			add(a[i].id,a[j].id);
		}
	}
	int ans=0;
	for(int j=1; j<=n-2; j++) {
		bmp.id=a[j].id,bmp.sum=a[j].num,bmp.dis=1,bmp.mx=a[j].num;
		q.push(bmp);
		while(!q.empty()) {
			edge tmp=q.front();
			q.pop();
			if(tmp.dis>=3&&tmp.sum>2*tmp.mx) {
				ans++;
			}
			for(int i=fst[tmp.id]; i; i=nxt[i]) {
				bmp.id=to[i],bmp.dis=tmp.dis+1,bmp.sum=tmp.sum+a[to[i]].num,bmp.mx=a[to[i]].num;
				q.push(bmp);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
