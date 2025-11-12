#include<bits/stdc++.h>
using namespace std;
int T,n,ans,a[100005],b[100005],c[100005];
struct stu {
	int a,b,c;
} id[100005],nc[100005],ncc[100005];
bool cmpa(stu x,stu y) {
	return min(x.a-x.b,x.a-x.c)<min(y.a-y.b,y.a-y.c);
}
bool cmpb(stu x,stu y) {
	return min(x.b-x.a,x.b-x.c)<min(y.b-y.a,y.b-y.c);
}
bool cmpc(stu x,stu y) {
	return min(x.c-x.b,x.c-x.a)<min(y.c-y.b,y.c-y.a);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		int ca=0,cb=0,cc=0,p=0,j=0,ans=0;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&id[i].a,&id[i].b,&id[i].c);
			if(id[i].a>id[i].b and id[i].a>id[i].c) {
				a[++ca]=i;
				ans+=id[i].a;
			} else if(id[i].b>id[i].c) {
				b[++cb]=i;
				ans+=id[i].b;
			} else {
				c[++cc]=i;
				ans+=id[i].c;
			}
		}
		if(ca>n/2) {
			for(int i=1; i<=ca; i++) {
				nc[i].a=id[a[i]].a;
				nc[i].b=id[a[i]].b;
				nc[i].c=id[a[i]].c;
			}
			sort(nc+1,nc+ca+1,cmpa);
			for(int i=1; i<=ca-n/2; i++) {
				if(cb==n/2) {
					p=1;
					j=i;
					break;
				}
				if(cc==n/2) {
					p=2;
					j=i;
					break;
				}
				if(nc[i].a-nc[i].b<nc[i].a-nc[i].c) {
					cb++;
					ans-=nc[i].a-nc[i].b;
				} else {
					cc++;
					ans-=nc[i].a-nc[i].c;
				}
			}
			if(p==1) {
				int size=ca-n/2-j;
				for(int i=j; i<=ca-n/2; i++) {
					ncc[i-j+1].a=nc[i].a;
					ncc[i-j+1].b=nc[i].b;
					ncc[i-j+1].c=nc[i].c;
				}
				for(int i=1; i<=size; i++)ans-=ncc[i].a-ncc[i].c;
			}
			if(p==2) {
				int size=ca-n/2-j;
				for(int i=j; i<=ca-n/2; i++) {
					ncc[i-j+1].a=nc[i].a;
					ncc[i-j+1].b=nc[i].b;
					ncc[i-j+1].c=nc[i].c;
				}
				for(int i=1; i<=size; i++)ans-=ncc[i].a-ncc[i].b;
			}
		} else if(cb>n/2) {
			for(int i=1; i<=cb; i++) {
				nc[i].a=id[b[i]].a;
				nc[i].b=id[b[i]].b;
				nc[i].c=id[b[i]].c;
			}
			sort(nc+1,nc+cb+1,cmpb);
			for(int i=1; i<=cb-n/2; i++) {
				if(ca==n/2) {
					p=1;
					j=i;
					break;
				}
				if(cc==n/2) {
					p=2;
					j=i;
					break;
				}
				if(nc[i].b-nc[i].a<nc[i].b-nc[i].c) {
					ca++;
					ans-=nc[i].b-nc[i].a;
				} else {
					cc++;
					ans-=nc[i].b-nc[i].c;
				}
			}
			if(p==1) {
				int size=cb-n/2-j;
				for(int i=j; i<=cb-n/2; i++) {
					ncc[i-j+1].a=nc[i].a;
					ncc[i-j+1].b=nc[i].b;
					ncc[i-j+1].c=nc[i].c;
				}
				for(int i=1; i<=size; i++)ans-=ncc[i].b-ncc[i].c;
			}
			if(p==2) {
				int size=cb-n/2-j;
				for(int i=j; i<=cb-n/2; i++) {
					ncc[i-j+1].a=nc[i].a;
					ncc[i-j+1].b=nc[i].b;
					ncc[i-j+1].c=nc[i].c;
				}
				for(int i=1; i<=size; i++)ans-=ncc[i].b-ncc[i].a;
			}
		} else {
			for(int i=1; i<=cc; i++) {
				nc[i].a=id[c[i]].a;
				nc[i].b=id[c[i]].b;
				nc[i].c=id[c[i]].c;
			}
			sort(nc+1,nc+cc+1,cmpc);
			for(int i=1; i<=cc-n/2; i++) {
				if(ca==n/2) {
					p=1;
					j=i;
					break;
				}
				if(cb==n/2) {
					p=2;
					j=i;
					break;
				}
				if(nc[i].c-nc[i].a<nc[i].c-nc[i].b) {
					ca++;
					ans-=nc[i].c-nc[i].a;
				} else {
					cb++;
					ans-=nc[i].c-nc[i].b;
				}
			}
			if(p==1) {
				int size=cc-n/2-j;
				for(int i=j; i<=cc-n/2; i++) {
					ncc[i-j+1].a=nc[i].a;
					ncc[i-j+1].b=nc[i].b;
					ncc[i-j+1].c=nc[i].c;
				}
				for(int i=1; i<=size; i++)ans-=ncc[i].c-ncc[i].b;
			}
			if(p==2) {
				int size=cc-n/2-j;
				for(int i=j; i<=cc-n/2; i++) {
					ncc[i-j+1].a=nc[i].a;
					ncc[i-j+1].b=nc[i].b;
					ncc[i-j+1].c=nc[i].c;
				}
				for(int i=1; i<=size; i++)ans-=ncc[i].c-ncc[i].a;
			}
		}
		printf("%d\n",ans);
	}
}
