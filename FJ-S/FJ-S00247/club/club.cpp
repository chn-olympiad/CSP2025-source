#include<bits/stdc++.h>
#define int long long
#define Z(x) (x*2)
#define Y(x) (x*2+1)
using namespace std;
int T,n;
struct sbb {
	int a,b,c;
	int cz,cd,zd;
	int maxx,minn;
} sb[100005];
int d[4][100005];
int gs[4];
void gx(int cs) {
	int wz=d[cs][0];
	while(wz>1&&sb[d[cs][wz]].cz<sb[d[cs][wz/2]].cz)swap(d[cs][wz],d[cs][wz/2]),wz/=2;
	return ;
}
void sc(int cs) {
	int wz=1;
	while(Z(wz)<=d[cs][0]) {
		if(Z(wz)==d[cs][0]) {
			if(sb[d[cs][wz]].cz>sb[d[cs][Z(wz)]].cz)swap(d[cs][Z(wz)],d[cs][wz]);
			break;
		}
		int minn=min({sb[d[cs][wz]].cz,sb[d[cs][Z(wz)]].cz,sb[d[cs][Y(wz)]].cz});
		if(minn==sb[d[cs][wz]].cz)break;
		if(minn==sb[d[cs][Z(wz)]].cz)swap(d[cs][wz],d[cs][Z(wz)]),wz=Z(wz);
		else swap(d[cs][wz],d[cs][Y(wz)]),wz=Y(wz);
	}
	return ;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--) {
		long long ans=0;
		gs[1]=gs[2]=gs[3]=0;
		d[1][0]=d[2][0]=d[3][0]=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>sb[i].a>>sb[i].b>>sb[i].c;
			sb[i].minn=min({sb[i].a,sb[i].b,sb[i].c});
			sb[i].maxx=max({sb[i].a,sb[i].b,sb[i].c});
			sb[i].cz=sb[i].maxx;
			sb[i].cz-=sb[i].a+sb[i].b+sb[i].c-sb[i].maxx-sb[i].minn;
			if(sb[i].a!=sb[i].minn&&sb[i].a!=sb[i].maxx)sb[i].cd=1;
			else if(sb[i].b!=sb[i].minn&&sb[i].b!=sb[i].maxx)sb[i].cd=2;
			else sb[i].cd=3;
			if(sb[i].a==sb[i].maxx)sb[i].zd=1;
			else if(sb[i].b==sb[i].maxx)sb[i].zd=2;
			else sb[i].zd=3;
		}
		for(int i=1; i<=n; i++) {
			int ZD=sb[i].zd;
			if(gs[ZD]<n/2) {
				gs[ZD]++;
				d[ZD][++d[ZD][0]]=i;
				gx(ZD);
				ans+=sb[i].maxx;
				continue;
			}
			int wz=d[ZD][1];
			if(sb[wz].cz>sb[i].cz) {
				gs[sb[i].cd]++;
				d[sb[i].cd][++d[sb[i].cd][0]]=i;
				gx(sb[i].cd);
				ans+=sb[i].maxx-sb[i].cz;
				continue;
			}
			ans-=sb[wz].cz;
			d[ZD][1]=i;
			sc(ZD);
			gs[sb[wz].cd]++;
			ans+=sb[i].maxx;
			d[sb[wz].cd][++d[sb[wz].cd][0]]=wz;
			gx(sb[wz].cd);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
