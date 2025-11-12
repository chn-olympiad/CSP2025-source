#include<bits/stdc++.h>
using namespace std;
#define mod 918258251
#define mod2 187524329
#define N 200050
#define M 5000050
int n, m, qm, i, j, k, x, y, ans, flag, cf[M], hx[M], aa, bb, a[N], b[N], xw[N], yw[N], xq[N], yq[N], q[N];
int cfp[M], hxp[M], aap, bbp, ap[N], bp[N], xqp[N], yqp[N];
char w[M], w2[M];
map<int, map<int, map<int, map<int, int> > > > r;
int qu(int x, int y) {
	return (hx[y]-1ll*cf[y-x+1]*hx[x-1]%mod+mod)%mod;
}
int qup(int x, int y) {
	return (hxp[y]-1ll*cfp[y-x+1]*hxp[x-1]%mod2+mod2)%mod2;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &qm);
	for (cfp[0]=cf[0]=i=1; i<=5000000; i++) cf[i] = 27ll*cf[i-1]%mod, cfp[i] = 27ll*cfp[i-1]%mod2;
	for (i=1; i<=n; i++) {
		scanf("%s%s", w+1, w2+1);
		m = strlen(w+1);
		for (j=1; j<=m; j++) {
			if (w[j] != w2[j]) break;
		}
		xw[i] = j-1;
		for (j=m; j; j--) {
			if (w[j] != w2[j]) break;
		}
		yw[i] = j+1, flag = m-j;
		if (xw[i] < m) {
			for (j=1; j<=xw[i]; j++) xq[i] = (27ll*xq[i]+w[j]-'a'+1)%mod;
			for (j=yw[i]; j<=m; j++) yq[i] = (27ll*yq[i]+w[j]-'a'+1)%mod;
			for (j=xw[i]+1; j<yw[i]; j++) a[i] = (27ll*a[i]+w[j]-'a'+1)%mod;
			for (j=xw[i]+1; j<yw[i]; j++) b[i] = (27ll*b[i]+w2[j]-'a'+1)%mod;
			for (j=1; j<=xw[i]; j++) xqp[i] = (27ll*xqp[i]+w[j]-'a'+1)%mod2;
			for (j=yw[i]; j<=m; j++) yqp[i] = (27ll*yqp[i]+w[j]-'a'+1)%mod2;
			for (j=xw[i]+1; j<yw[i]; j++) ap[i] = (27ll*ap[i]+w[j]-'a'+1)%mod2;
			for (j=xw[i]+1; j<yw[i]; j++) bp[i] = (27ll*bp[i]+w2[j]-'a'+1)%mod2;
			q[i] = r[a[i]][b[i]][ap[i]][bp[i]], r[a[i]][b[i]][ap[i]][bp[i]] = i;
		}
		yw[i] = flag;
	}
	for (i=1; i<=qm; i++) {
		scanf("%s%s", w+1, w2+1);
		m = strlen(w+1);
		if (m != strlen(w2+1)) {
			printf("0\n");
			continue;
		}
		for (j=1; j<=m; j++) {
			if (w[j] != w2[j]) break;
		}
		x = j-1;
		for (j=m; j; j--) {
			if (w[j] != w2[j]) break;
		}
		y = j+1;
		for (aa=0, j=x+1; j<y; j++) aa = (27ll*aa+w[j]-'a'+1)%mod;
		for (bb=0, j=x+1; j<y; j++) bb = (27ll*bb+w2[j]-'a'+1)%mod;
		for (j=1; j<=m; j++) hx[j] = (27ll*hx[j-1]+w[j]-'a'+1)%mod;
		for (aap=0, j=x+1; j<y; j++) aap = (27ll*aap+w[j]-'a'+1)%mod2;
		for (bbp=0, j=x+1; j<y; j++) bbp = (27ll*bbp+w2[j]-'a'+1)%mod2;
		for (j=1; j<=m; j++) hxp[j] = (27ll*hxp[j-1]+w[j]-'a'+1)%mod2;
		for (ans=0, j=r[aa][bb][aap][bbp]; j; j=q[j]) {
			if (x-xw[j]+1>0 && y+yw[j]-1<=m && xq[j] == qu(x-xw[j]+1, x) && yq[j] == qu(y, y+yw[j]-1) && xqp[j] == qup(x-xw[j]+1, x) && yqp[j] == qup(y, y+yw[j]-1)) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

