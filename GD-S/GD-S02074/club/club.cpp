#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T;
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
ll n,a[100001],b[100001],c[100001],l=0,nn;
void f(ll ax,ll bx,ll cx,ll op,ll kl) {
	op++;
	if(op>n) {
		l=max(l,kl);
		return;
	}
	if(ax<nn) {
		f(ax+1,bx,cx,op,kl+a[op]);
	}
	if(bx<nn) {
		f(ax,bx+1,cx,op,kl+b[op]);
	}
	if(cx<nn) {
		f(ax,bx,cx+1,op,kl+c[op]);
	}
}
struct node {
	ll a,b,c,d,e;
} d[100001];
bool cmp(node x,node y) {
	return x.d>y.d;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	for(int tt=1; tt<=T; tt++) {
		n=read();
		ll x,y,z;
		l=0;
		nn=n/2;
		ll hj=0;
		for(int i=1; i<=n; i++) {
			x=read();
			y=read();
			z=read();
			a[i]=x;
			b[i]=y;
			c[i]=z;
			if(c[i]!=0) {
				hj=1;
			}
		}
		if(hj==0) {
			for(int i=1; i<=n; i++) {
				d[i].a=a[i];
				d[i].b=b[i];
				d[i].d=abs(a[i]-b[i]);
			}
			sort(d+1,d+1+n,cmp);
			ll aax=0,bbx=0;
			for(int i=1; i<=n; i++) {
				if(d[i].a>=d[i].b) {
					if(aax<nn) {
						aax++;
						l+=d[i].a;
					} else {
						bbx++;
						l+=d[i].b;
					}
				} else {
					if(bbx<nn) {
						bbx++;
						l+=d[i].b;
					} else {
						aax++;
						l+=d[i].a;
					}
				}
			}
		} else {
			if(n<30) {
				f(0,0,0,0,0);
			} else {
				ll fgh=0;
				for(int i=1; i<=n; i++) {
					d[i].a=a[i];
					d[i].b=b[i];
					d[i].c=c[i];

					fgh=max(a[i],max(b[i],c[i]));
					d[i].e=fgh;
					if(a[i]==fgh) {
						if(b[i]>c[i]) {
							d[i].d=a[i]-b[i];
						} else {
							d[i].d=a[i]-c[i];
						}
					}
					if(b[i]==fgh) {
						if(a[i]>c[i]) {
							d[i].d=b[i]-a[i];
						} else {
							d[i].d=b[i]-c[i];
						}
					}
					if(c[i]==fgh) {
						if(b[i]>a[i]) {
							d[i].d=c[i]-b[i];
						} else {
							d[i].d=c[i]-a[i];
						}
					}
				}
				sort(d+1,d+1+n,cmp);
				ll aax=0,bbx=0,ccx=0;
				for(int i=1; i<=n; i++) {
					if(d[i].a==d[i].e) {
						if(aax<nn) {
							aax++;
							l+=d[i].a;
						} else {
							if(d[i].b>=d[i].c) {
								bbx++;
								l+=d[i].b;
							} else {
								ccx++;
								l+=d[i].c;
							}
						}
					}
					if(d[i].b==d[i].e) {
						if(bbx<nn) {
							bbx++;
							l+=d[i].b;
						} else {
							if(d[i].a>=d[i].c) {
								aax++;
								l+=d[i].a;
							} else {
								ccx++;
								l+=d[i].c;
							}
						}
					}
					if(d[i].c==d[i].e) {
						if(ccx<nn) {
							ccx++;
							l+=d[i].c;
						} else {
							if(d[i].b>=d[i].a) {
								bbx++;
								l+=d[i].b;
							} else {
								aax++;
								l+=d[i].a;
							}
						}
					}
				}
			}
		}
		cout<<l<<endl;
	}
	return 0;
}

