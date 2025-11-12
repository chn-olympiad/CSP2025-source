#include<bits/stdc++.h>
using namespace std;
int n;
struct st{
	int a,b,c;
};
st a[100010],b[100010],c[100010];
int ai,bi,ci;
st s;
int maxn,ans;
inline bool cmpaa(st aa,st bb) {return min(aa.a-aa.b,aa.a-aa.c)>min(bb.a-bb.b,bb.a-bb.c);}
inline bool cmpbb(st aa,st bb) {return min(aa.b-aa.a,aa.b-aa.c)>min(bb.b-bb.a,bb.b-bb.c);}
inline bool cmpcc(st aa,st bb) {return min(aa.c-aa.b,aa.c-aa.a)>min(bb.c-bb.b,bb.c-bb.a);}
void solution() {
	cin>>n;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	ai=0;
	bi=0;
	ci=0;
	for(int i=1;i<=n;i++) {
		cin>>s.a>>s.b>>s.c;
		maxn=max(s.a,max(s.b,s.c));
		if(maxn==s.a) {
			a[ai]=s;
			ai++;
		}
		else if(maxn==s.b) {
			b[bi]=s;
			bi++;
		}
		else if(maxn==s.c) {
			c[ci]=s;
			ci++;
		}
	}
	if(ai>(n/2)) {
		sort(a,a+ai,cmpaa);
		for(int i=n/2;i<ai;i++) {
			if(a[i].b>a[i].c) {
				b[bi]=a[i];
				bi++;
			} 
			else {
				c[ci]=a[i];
				ci++;
			}
		}
		ai=n/2;
	}
	if(bi>(n/2)) {
		sort(b,b+bi,cmpbb);
		for(int i=n/2;i<bi;i++) {
			if(b[i].a>b[i].c) {
				a[ai]=b[i];
				ai++;
			} 
			else {
				c[ci]=b[i];
				ci++;
			}
		}
		bi=n/2;
	}
	if(ci>(n/2)) {
		sort(c,c+ci,cmpcc);
		for(int i=n/2;i<ci;i++) {
			if(c[i].a>c[i].b) {
				a[ai]=c[i];
				ai++;
			} 
			else {
				b[bi]=c[i];
				bi++;
			}
		}
		ci=n/2;
	}
	ans=0;
	for(int i=0;i<ai;i++) ans+=a[i].a;
	for(int i=0;i<bi;i++) ans+=b[i].b;
	for(int i=0;i<ci;i++) ans+=c[i].c;
	cout<<ans<<endl;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) solution();
} 
