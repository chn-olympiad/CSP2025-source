#include<bits/stdc++.h>
using namespace std;
struct node {
	int v,id;
} a[100010],b[100010],c[100010];
bool bol[100010];
int t,n;
bool cmp(node A,node B) {
	return A.v>B.v;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		memset(bol,0,sizeof(bol));
		cin>>n;
		bool b1=0,b2=0;
		for(int i=1; i<=n; ++i) {
			cin>>a[i].v>>b[i].v>>c[i].v;
			if(b[i].v==1) {
				b1=1;
			}
			if(c[i].v==1) {
				b2=1;
			}
			a[i].id=b[i].id=c[i].id=i;
		}	if(n==2){
			int aa=a[1].v+b[2].v,bb=a[1].v+c[2].v,cc=b[1].v+a[2].v,dd=b[1].v+c[2].v,ee=c[1].v+a[2].v,ff=c[1].v+b[2].v;
			int s=max(aa,max(bb,max(cc,max(dd,max(ee,ff)))));
			cout<<s<<'\n';
			continue;
		}
		int ans=0;
		stable_sort(a+1,a+n+1,cmp);
		stable_sort(b+1,b+n+1,cmp);
		stable_sort(c+1,c+n+1,cmp);
		if(!b1&&!b2) {
			for(int i=1; i<=n/2; i++) {
				ans+=a[i].v;
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=3; j++) {
				int maxx=0,d=0;
				if(a[i].v>=b[i].v&&!bol[a[i].id]) {
					maxx=a[i].v;
					d=a[i].id;
					if(a[i].v>=c[i].v&&!bol[c[i].id]) {
						maxx=a[i].v;
						d=a[i].id;
					} else {
						maxx=c[i].v;
						d=c[i].id;
					}
				} else {
					if(b[i].v>=c[i].v&&!bol[b[i].id]) {
						maxx=b[i].v;
						d=b[i].id;
					} else {
						maxx=c[i].v;
						d=c[i].id;
					}
				}
				ans+=maxx;
				bol[d]=1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
