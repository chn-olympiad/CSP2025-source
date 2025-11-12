#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int n;
struct node {
	int a,b,c,id;
	int cab,cac,cbc;
}a[N];

bool cmd(node a,node b) {
	return a.cab>b.cab;
}

bool cmd2(node a,node b) {
	int u,v;
	if (a.cab>0) u=a.cac;
	else u=a.cbc;
	if (b.cab>0) v=b.cac;
	else v=b.cbc;
	return u<v; 
}

bool cmd3(node a,node b) {
	if (a.id==3&&b.id==3) {
		return max(a.cac, a.cbc) > max(b.cac, b.cbc);
	}
	return a.id>b.id;
}

bool cmd4(node a,node b) {
	return a.cab<b.cab;
}

void print(int n) {
	int ans=0;
	for (int i=1;i<=n;i++) {
		if (a[i].id==1) ans+=a[i].a;
		if (a[i].id==2) ans+=a[i].b;
		if (a[i].id==3) ans+=a[i].c; 
	}
	printf("%d\n", ans);
	return ;
}

void solve2() {
	int ans=0;
	// 1.假设全部都为1，与2的差小的优先放2
	sort(a+1,a+1+n,cmd4);
	for (int i=1;i<=n;i++) {
		if (i<=n/2) {
			ans+=a[i].b;
		} else {
			ans+=a[i].a;
		}
	} 
	printf("%d\n", ans);
	return ;
} 

void solve() {
	int f=1; 
	int i1=0,i2=0,i3=0; 
	scanf("%d", &n);
	for (int i=1;i<=n;i++) {
		int u,v,w;
		scanf("%d%d%d", &u, &v, &w);
		a[i]={u,v,w,1, u-v, u-w, v-w};
		if (w) f=0;
	}
	if (f) {
		solve2();
		return ;
	}
	sort(a+1,a+1+n,cmd); 
	
	for (int i=1;i<=n;i++) {
		if (a[i].cab>0) i1++,a[i].id=1;
		else a[i].id=2,i2++;
	}

	// 把n/2个人传入3队 
	sort(a+1,a+1+n,cmd2);
	for (int i=1;i<=n/2;i++) {
		if (a[i].cab>0) {
			i1--;
		}
		else {
			i2--;
		}
		a[i].id=3;
		i3++;
	}
	sort(a+1,a+1+n,cmd3);
	// 针对第三队进行单独计算，将可以放入12队的（与1，2差在0以下的）尽量放入
	for (int i=1;i<=i3;i++) {
		if (a[i].cac>a[i].cbc && a[i].cac>0 && i1<n/2) {
			a[i].id=1;
			i1++;
		} else if (a[i].cbc>a[i].cac && a[i].cbc>0 && i2<n/2) {
			a[i].id=2;
			i2++;
		} else if (i1<n/2 && a[i].cac>0) {
			a[i].id=1;
			i1++;
		} else if (i2<n/2 && a[i].cbc>0) {
			a[i].id=2;
			i2++;
		}
	}  
	print(n);
	return ;
}


signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
} 
