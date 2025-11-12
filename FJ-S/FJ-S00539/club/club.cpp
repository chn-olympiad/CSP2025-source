#include<bits/stdc++.h>
using namespace std;
struct club{
	int a,b,c,id;
}a[100010];
struct club2{
	int v,id,cid,index;
}b[100010];
int tmp[100010];
int siz[5];
int cida(int a,int b,int c) {
	if(a>=b) {
		if(a<c) return a;
		if(a>c) {
			if(b>c) return b;
			else return c;
		} 
	}
	if(a<=b) {
		if(a>c) return a;
		if(a<c) {
			if(b>c) return c;
			else return b;
		} 
	}
	return -1;
}
bool cmp(club2 a,club2 b) {
	return a.v<b.v;
}
void solve() {
	int n,ans=0;
	memset(siz,0,sizeof siz);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].a>>a[i].b>>a[i].c;
		b[i].index=i;
		b[i].v=max(a[i].a,max(a[i].b,a[i].c))-cida(a[i].a,a[i].b,a[i].c);
		//cout<<b[i].v<<" "<<cida(a[i].a,a[i].b,a[i].c)<<"\n";
		int t=max(a[i].a,max(a[i].b,a[i].c));
		if(t==a[i].a) {
			b[i].id=1;
			siz[1]++; 
		}
		if(t==a[i].b) {
			b[i].id=2;
			siz[2]++; 
		}
		if(t==a[i].c) {
			b[i].id=3;
			siz[3]++; 
		}
		t=cida(a[i].a,a[i].b,a[i].c);
		if(t==a[i].a) {
			b[i].cid=1;
		}
		if(t==a[i].b) {
			b[i].cid=2;
		}
		if(t==a[i].c) {
			b[i].cid=3; 
		}
	} 
	//可以证明，最多仅有一组数量大于n/2 
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++) {
		//cout<<a[b[i].index].a<<" "<<a[b[i].index].b<<" "<<a[b[i].index].c<<" "<<b[i].v<<" "<<b[i].id<<"\n";
		if(siz[b[i].id]>n/2) {
			if(b[i].cid==1) {
				ans+=a[b[i].index].a;
			}
			if(b[i].cid==2) {
				ans+=a[b[i].index].b;
			}
			if(b[i].cid==3) {
				ans+=a[b[i].index].c;
			}
			siz[b[i].id]--;
		}
		else {
			if(b[i].id==1) {
				ans+=a[b[i].index].a;
			}
			if(b[i].id==2) {
				ans+=a[b[i].index].b;
			}
			if(b[i].id==3) {
				ans+=a[b[i].index].c;
			}
		}
	//	cout<<ans<<"\n";
	}
	cout<<ans<<"\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}
