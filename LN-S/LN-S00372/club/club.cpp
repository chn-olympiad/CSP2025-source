#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node {
	int x,y;
}a[N][4];
int b[N],c[4];
int t,n,ans;
int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
void write(int x) {
	if(x<0){putchar('-');x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void print(int x) {
	write(x);
	puts("");
}
void init() {
	ans=0;
	for(int i=1;i<=3;i++) c[i]=0;
}
bool cmp1(node u,node v) {
	return u.x>v.x;
}
bool cmp2(int u,int v) {
	return (a[u][1].x-a[u][2].x)>(a[v][1].x-a[v][2].x);
}
void solve() {
	init();
	n=read();
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=3;j++) {
			a[i][j].x=read();
			a[i][j].y=j;
		}
	}
	for(int i=1;i<=n;i++) sort(a[i]+1,a[i]+4,cmp1);
	for(int i=1;i<=n;i++) b[i]=i;
	sort(b+1,b+n+1,cmp2);
	for(int i=1;i<=n;i++) {
		if(c[a[b[i]][1].y]<n/2) {
			c[a[b[i]][1].y]++;
			ans+=a[b[i]][1].x;
		}
		else {
			c[a[b[i]][2].y]++;
			ans+=a[b[i]][2].x;
		}
	}
	print(ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--) solve();
	return 0;
}
