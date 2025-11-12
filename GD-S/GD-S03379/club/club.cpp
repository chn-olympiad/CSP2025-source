#include <bits/stdc++.h>
using namespace std;
long long t,n,d[3],ans,ia,ib,ic,op;
struct p {
	long long ad[3];
	int mxd;
	long long l;
}a[100005];
bool cmp (p ab,p bb) {
	if (ab.mxd!=bb.mxd) {
		if (ab.mxd==op) return true;
		if (bb.mxd==op) return false;
		return ab.mxd<bb.mxd;
	}
	return ab.l<bb.l;
}
void rdc (int op2) {
	op=op2;
	sort(a+1,a+n+1,cmp);
	long long t=1;
	while (d[op]>n/2) {
		ans-=a[t].l;
		d[op]--;
	}
	return ;
}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--) {
		memset(d,0,sizeof(d));
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>ia>>ib>>ic;
			if (ia>=ib) {
				if (ia>=ic) {
					a[i].mxd=0;
					a[i].l=ia-max(ib,ic);
				}
				else {
					a[i].mxd=2;
					a[i].l=ic-max(ia,ib);
				}
			}
			else {
				if (ib>=ic) {
					a[i].mxd=1;
					a[i].l=ib-max(ia,ic);
				}
				else {
					a[i].mxd=2;
					a[i].l=ic-max(ia,ib);
				}
			}
			a[i].ad[0]=ia;
			a[i].ad[1]=ib;
			a[i].ad[2]=ic;
			d[a[i].mxd]++;
			ans+=a[i].ad[a[i].mxd];
		}
		if (d[0]>n/2) rdc(0);
		if (d[1]>n/2) rdc(1);
		if (d[2]>n/2) rdc(2);
		cout<<ans<<"\n";
	}
	return 0;
}

