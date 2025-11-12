#include<bits/stdc++.h>
using namespace std;
long long t,n;
struct node {
	long long a,b,c;
} a[100001];
bool cmp(node a,node b) {
	if(max({a.a,a.b,a.c})>max({b.a,b.b,b.c})) return 1;
	if(a.a==b.a){
		if(a.b==b.b){
			return a.c>b.c;
		}else{
			return a.b>b.b;
		}
	}
	if(a.b==b.b){
		if(a.a==b.a){
			return a.a>b.a;
		}else{
			return a.c>b.c;
		}
	}
	if(a.c==b.c){
		if(a.b==b.b){
			return a.b>b.b;
		}else{
			return a.a>b.a;
		}
	}
	return 0;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		long long cnta=0,cntb=0,cntc=0,ans=0;
		memset(a,0,sizeof(a));
		for(long long i=1; i<=n; i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		for(long long i=1; i<=n; i++) {
			if(max({a[i].a,a[i].b,a[i].c})==a[i].a) {
				if(cnta+1>n/2) {
					if(a[i].b>a[i].c) {
						cntb++;
						ans+=a[i].b;
						continue;
					} else {
						cntc++;
						ans+=a[i].c;
						continue;
					}
				}
				cnta++;
				ans+=a[i].a;
			}
			else if(max({a[i].a,a[i].b,a[i].c})==a[i].b) {
				if(cntb+1>n/2) {
					if(a[i].a>a[i].c) {
						cnta++;
						ans+=a[i].a;
						continue;
					} else {
						cntc++;
						ans+=a[i].c;
						continue;
					}
				}
				cntb++;
				ans+=a[i].b;
			}
			else if(max({a[i].a,a[i].b,a[i].c})==a[i].c) {
				if(cntc+1>n/2) {
					if(a[i].a>a[i].b) {
						cnta++;
						ans+=a[i].a;
						continue;
					} else {
						cntb++;
						ans+=a[i].b;
						continue;
					}
				}
				cntc++;
				ans+=a[i].c;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
