#include <bits/stdc++.h>
using namespace std;
long long n,m,k,c[10005][15],f[10005][2],el,iu,iv,iw,mc,mt,bn,blk,rans,ans;
struct ln {
	int u;
	int v;
	long long w;
	int p;
}e[1500005],in;
bool cmp (ln aa,ln b) {
	return aa.w<b.w;
}
bool a=true;
long long found (long long x) {
	if (f[x][0]==0||f[x][1]!=bn) {
		f[x][0]=x;
		f[x][1]=bn;
	}
	long long px=x;
	while (x!=f[x][0]) x=f[x][0];
	f[px][0]=x;
	return x;
}
void cnt (long long x,long long y) {
	long long fx=found(x),fy=found(y);
	if (fx==fy) return ;
	if (fx>fy) swap(fx,fy);
	f[fy][0]=fx;
	blk--;
	rans+=iw;
	//cout<<iu<<" "<<iv<<" "<<iw<<"\n";
	return ;
}
long long mst () {
	blk=n;
	rans=0;
	for (int i=1;i<=el;i++) {
		in=e[i];
		if (in.p!=0) if ((1<<(in.p-1))&bn) continue;
		iu=in.u;
		iv=in.v;
		iw=in.w;
		cnt(iu,iv);
		if (blk==1) return rans;
	}
	return rans;
}
int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	in.p=0;
	for (int i=1;i<=m;i++) {
		cin>>iu>>iv>>iw;
		if (iu>iv) swap(iu,iv);
		in.u=iu;
		in.v=iv;
		in.w=iw;
		e[++el]=in;
	}
	for (int i=1;i<=k;i++) {
		cin>>c[0][i];
		if (c[0][i]) a=false;
		mc=1000000009;
		in.p=i;
		for (int j=1;j<=n;j++) {
			cin>>c[j][i];
			if (c[j][i]<mc) {
				mc=c[j][i];
				mt=j;
			}
		}
		if (mc) a=false;
		c[0][i]+=mc;
		for (int j=1;j<=n;j++) {
			if (j!=mt) {
				in.u=mt;
				in.v=j;
				in.w=c[j][i];
				if (in.u>in.v) swap(in.u,in.v);
				e[++el]=in;
			}
		}
	}
	sort(e+1,e+el+1,cmp);
	if (!a) bn=(1<<k)-1;
	ans=mst();
	cout<<ans<<"\n";
	if ((!a)&&k>0) {
		for (bn=0;bn<(1<<k)-1;bn++) {
			mc=0;
			for (int i=1;i<=k;i++) if (bn^(1<<(i-1))) mc+=c[0][i];
			ans=min(ans,mst()+mc);
		}
	}
	cout<<ans;
	return 0;
}

