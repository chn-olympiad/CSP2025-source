#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+2;
int n,f[512][512][512];
struct node{
	int a,b,c,oc,mx;
	void read(){
		cin >> a >> b >> c;
		if(a>=b&&a>=c) mx=1,oc=a-max(b,c);
		if(b>=a&&b>=c) mx=2,oc=b-max(a,c);
		if(c>=a&&c>=b) mx=3,oc=c-max(a,b);
	}
}m[maxn];
inline bool cmp(node x,node y){
	return x.oc>y.oc;
}
void solve1(){
	memset(f,0,sizeof f);
	for(register int i=0; i<=n/2; i++){
		for(register int j=0; j<=n/2; j++){
			for(register int k=0; k<=n/2; k++){
				if(i+j+k>n) break;
				if(k) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+m[i+j+k].c);
				if(j) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+m[i+j+k].b);
				if(i) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+m[i+j+k].a);
			}
		}
	}
	int ans=0;
	for(register int i=0; i<=n/2; i++){
		for(register int j=i; j-i<=n/2; j++){
			if(n-j>n/2) continue;
			ans=max(ans,f[i][j-i][n-j]);
		}
	}
	cout << ans << '\n';
}//±©Á¦
void solve2(){
	sort(m+1,m+n+1,cmp);
	int ans=0,cnta=0,cntb=0,cntc=0;
	for(register int i=1; i<=n; i++){
		if(m[i].mx==1){
			ans+=m[i].a;
			if(cnta>=n/2) ans-=m[i].oc;
		}
		if(m[i].mx==2){
			ans+=m[i].b;
			if(cntb>=n/2) ans-=m[i].oc;
		}
		if(m[i].mx==3){
			ans+=m[i].c;
			if(cntc>=n/2) ans-=m[i].oc;
		}
	}
	cout << ans << '\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while(q--){
		cin >> n;
		for(register int i=1; i<=n; i++)
			m[i].read();
		solve2();
	}
	return 0;
}
