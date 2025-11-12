#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#define N 100005
using std::cout;
using std::cin;
using std::sort;
using std::max;
using std::min;
struct stu {
	int val,bh;
};
struct cmp {
	bool operator()(stu a,stu b) {
		return a.val>b.val;
	}
};
bool operator<(stu a,stu b) {
	return a.val<b.val;
}
bool vis[N];
int a[N][4];
stu b[N],c[N],d[N];
int n,ans,mxs;
void read() {
	cin>>n;
	mxs=n>>1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=3; j++) {
			cin>>a[i][j];
			switch(j) {
				case 1:
					b[i]=(stu) {
						a[i][j],i
					};
					break;
				case 2:
					c[i]=(stu) {
						a[i][j],i
					};
					break;
				case 3:
					d[i]=(stu) {
						a[i][j],i
					};
					break;
			}
		}
}
void solve() {
	sort(b+1,b+n+1,cmp());
	sort(c+1,c+n+1,cmp());
	sort(d+1,d+n+1,cmp());
	bool fb=false,fc=false,fd=false;
	for(int b1=1,c1=1,d1=1,sub=0,suc=0,sud=0; b1<=n||c1<=n||d1<=n;) {
		while(vis[b[b1].bh])
			b1++;
		while(vis[c[c1].bh])
			c1++;
		while(vis[d[d1].bh])
			d1++;
		stu x=max(max(b[b1],c[c1]),d[d1]);
		vis[x.bh]=true;
		if(b[b1].bh==c[c1].bh&&c[c1].bh==d[d1].bh&&!fb&&!fc&&!fd) {
			int rp=min(sub,min(suc,sud));
			if(rp==sub)
				sub++;
			else if(rp==suc)
				suc++;
			else
				sud++;
		} else if(x.bh!=d[d1].bh&&b[b1].bh==c[c1].bh&&!fb&&!fc) {
			int rp=min(sub,suc);
			if(rp==sub)
				sub++;
			else
				suc++;
		} else if(x.bh!=b[b1].bh&&d[d1].bh==c[c1].bh&&!fc&&!fd) {
			int rp=min(sud,suc);
			if(rp==sud)
				sud++;
			else
				suc++;
		} else if(x.bh!=c[c1].bh&&b[b1].bh==d[d1].bh&&!fb&&!fd) {
			int rp=min(sub,sud);
			if(rp==sub)
				sub++;
			else
				sud++;
		} else if(x.bh==b[b1].bh&&!fb)
			sub++;
		else if(x.bh==c[c1].bh&&!fc)
			suc++;
		else if(x.bh==d[d1].bh&&!fd)
			sud++;
		if(sub>=mxs)
			fb=true;
		else if(suc>=mxs)
			fc=true;
		else if(sud>=mxs)
			fd=true;
		ans+=x.val;
	}
	cout<<ans<<'\n';
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		memset(d,0,sizeof d);
		read();
		solve();
	}
	return 0;
}
