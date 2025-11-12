#include<bits/stdc++.h>
using namespace std;
int a[500008];
struct sd {
	int x,y,c;
}z[500060];
int f[500003];
bool cmp(sd a,sd b) {
	if(a.c==b.c) {
		if(a.x!=b.x) {
			return a.x<b.x;
		} else {
			return a.y<b.y;
		}
	} else {
		return a.c<b.c;
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,o=1,l=0;
	long long t;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1; i<=n; i++) {
		if(a[i]==k) {
			z[++l].x=i;
			z[l].y=i;
			z[l].c=1;
		}
		t=a[i];
		for(int j=i+1; j<=n; j++) {
			t=t^a[j];
			if(t==k) {
				z[++l].x=i;
				z[l].y=j;
				z[l].c=j-i+1;
			}
		}
	}
	t=0;
	sort(z+1,z+l+1,cmp);
	for(int i=1; i<=l; i++) {
		if(z[i].x!=z[i-1].x) {
			for(int j=z[i].x; j<=z[i].y; j++) {
				if(f[j]==1) {
					o=0;
					break;
				}
			}
			if(o==1) {
				t++;
				for(int j=z[i].x; j<=z[i].y; j++) {
					f[j]=1;
				}
			}
			o=1;
		}
	}
	printf("%lld",t);
	return 0;
}
