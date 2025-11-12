#include<bits/stdc++.h>
using namespace std;
long long n,m,k,m2;
struct node {
	long long x,y,l;
} a[2000005],b[4000005];
bool cmp(node x,node y) {
	return x.l<y.l;
}
long long g[15][10005];
long long f[100005];
long long ans[2050],res;
long long c[15];
int find(int x) {
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
inline void check(int zt,int n,int m,int k) {
	int nn=n;
	m2=0;
	for(int i=1; i<=k; i++) {
		if(((zt>>i-1)&1)==1) {
			n++;
			ans[zt]+=c[i];
			for(int j=1; j<=nn; j++) {
				b[++m2].x=n;
				b[m2].y=j;
				b[m2].l=g[i][j];
			}
		}
	}
	sort(b+1,b+m2+1,cmp);
	for(int i=1; i<=n; i++) {
		f[i]=i;
	}
	int i1=1,i2=1;
	//cout<<"read is ok\n";
	//cout<<zt<<' '<<m<<" "<<m2<<" : \n";
	while(i1<=m||i2<=m2) {
		node now;
		if(i1>m){
			now=b[i2],i2++;
		}
		else if(i2>m2){
			now=a[i1],i1++;
		}
		else if(a[i1].l<b[i2].l){
			now=a[i1],i1++;
		}
		else {
			now=b[i2],i2++;
		}
		int fx=find(now.x);
		int fy=find(now.y);
		if(fx!=fy) {
			f[fx]=fy;
			ans[zt]+=now.l;
			n--;
			//cout<<"1 "<<now.x<<' '<<now.y<<" "<<now.l<<"\n";
		}if(n==1)break;
		//else cout<<"0 "<<now.x<<' '<<now.y<<" "<<now.l<<"\n";
	}
	//ans[zt]=LLONG_MAX;
	return;
}
inline long long read() {
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch==45)f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void so() {
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		a[i].x=read();
		a[i].y=read();
		a[i].l=read();
	}
	for(int i=1; i<=k; i++) {
		c[i]=read();
		for(int j=1; j<=n; j++) {
			g[i][j]=read();
		}
	}
	//cout<<"read is ok\n";
	sort(a+1,a+m+1,cmp);
	check(0,n,m,k);
	res=ans[0];
	for(int i=1; i<=(1<<k)-1; i++) {
		check(i,n,m,k);
		res=min(res,ans[i]);
	}
	cout<<res;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	so();
	return 0;
}
