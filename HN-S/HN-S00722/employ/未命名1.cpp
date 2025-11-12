#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,x[N],y[N],z[N],l[N];
int a[N],b[N],c[N];
struct E{
	int l,r;
}e[N];
int cmp(E g,E h){
	return g.l>h.l;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0,fi=0,se=0,th=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				x[++fi]=i;
			}
			if(b[i]>a[i]&&b[i]>c[i]){
				y[++se]=i;
			}
			if(c[i]>b[i]&&c[i]>a[i]){
				z[++th]=i;
			}
		}
		if(fi>n/2){
			for(int i=1;i<=fi;i++){
				e[i].l=a[x[i]]-max(b[x[i]],c[x[i]]);
				e[i].r=x[i];
			}
			sort(e+1,e+fi+1,cmp);
			for(int i=n/2+1;i<=fi;i++){
				if(b[e[i].r]>=c[e[i].r]){
					y[++se]=e[i].r;
				}else{
					z[++th]=e[i].r;
				}
				a[e[i].r]=0;
			}
		}
		if(se>n/2){
			for(int i=1;i<=se;i++){
				e[i].l=b[y[i]]-max(a[y[i]],c[y[i]]);
				e[i].r=y[i];
			}
			sort(e+1,e+se+1,cmp);
			for(int i=n/2+1;i<=se;i++){
				if(a[e[i].r]>=c[e[i].r]){
					x[++fi]=e[i].r;
				}else{
					z[++th]=e[i].r;
				}
				b[e[i].r]=0;
			}
		}
		if(th>n/2){
			for(int i=1;i<=th;i++){
				e[i].l=c[z[i]]-max(b[z[i]],a[z[i]]);
				e[i].r=z[i];
			}
			sort(e+1,e+th+1,cmp);
			for(int i=n/2+1;i<=th;i++){
				if(b[e[i].r]>=a[e[i].r]){
					y[++se]=e[i].r;
				}else{
					x[++fi]=e[i].r;
				}
				c[e[i].r]=0;
			}
		}
		for(int i=1;i<=fi;i++)ans+=a[x[i]];
		for(int i=1;i<=se;i++)ans+=b[y[i]];
		for(int i=1;i<=th;i++)ans+=c[z[i]];
		cout<<ans<<endl;
	}
	return 0;
}
