#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read() {
	ll op=1,x=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') {
			op=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*op;
}
ll n,h[411111],m,k,kk[100],kkk[20][20001];
ll sd[100001];
ll qwe=0;
ll find(ll x) {
	if(h[x]!=x) {
		return h[x]=find(h[x]);
	}
	return x;
}
struct node {
	int u,v;//,h;
	ll op;
} a[4111111];
bool cmp(node x,node y) {
	return x.op<y.op;
}
ll kl=0;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1; i<=n; i++) {
		h[i]=i;
	}
	ll x,y,z,ans=0,tyu=0;
	for(int i=1; i<=m; i++) {
		x=read();
		y=read();
		z=read();
		a[++ans].u=x;
		a[ans].v=y;
		a[ans].op=z;
		tyu=max(tyu,z);
	//	a[ans].h=ans;
	}
	for(int i=1; i<=k; i++) {
		kk[i]=read();
		for(int j=1; j<=n; j++) {
			kkk[i][j]=read();
		}
	}
	if(k!=0) {
		ll azxs=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				for(int jj=1; jj<=k; jj++) {
					azxs=kkk[jj][i]+kkk[jj][j]+kk[jj];
					if(azxs>tyu){
						continue;
					}
					a[++ans].u=i;
					a[ans].v=j;
					a[ans].op=azxs;
					//a[ans].h=ans;
				}
			}
		}
	}
	sort(a+1,a+1+ans,cmp);
	for(int i=1; i<=ans; i++) {
		x=find(a[i].u);
		y=find(a[i].v);
		if(x!=y) {
			kl+=a[i].op;
		//	cout<<kl<<endl;
			qwe++;
			sd[qwe]=i;
			h[y]=x;
		}
		if(qwe==n-1) {
			break;
		}
	}
	cout<<kl;
	return 0;
}
