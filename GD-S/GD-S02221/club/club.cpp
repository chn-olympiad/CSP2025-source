#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct Node{
	int x,y,z;
	int is;
}a[N];

////////////////////
struct Node1{
	int id,club;
};
int getnum1(int id,int club) {
	if (club==1) return a[id].x;
	if (club==2) return a[id].y;
	return a[id].z;
}
int cmp1(Node1 n1,Node1 n2) {
	return getnum1(n1.id,n1.club)>getnum1(n2.id,n2.club);
}
void solve1() { //ÌØÐÔC 
	vector<Node1> ve;
	for (int i=1;i<=n;i++) {
		if (a[i].x>=max(a[i].y,a[i].z)) {
			ve.push_back({i,1});
		}else if (a[i].y>=max(a[i].x,a[i].z)) {
			ve.push_back({i,2});
		}else {
			ve.push_back({i,3});
		}
	}
	sort(ve.begin(),ve.end(),cmp1);
	int cntx=0,cnty=0,cntz=0;
	int ans=0;
	for (int i=0;i<ve.size();i++) {
		if (ve[i].club==1) {
			if (cntx<n/2) {
				cntx++;
				ans+=getnum1(ve[i].id,ve[i].club);
				a[ve[i].id].is=1;
			}
		}
		if (ve[i].club==2) {
			if (cnty<n/2) {
				cnty++;
				ans+=getnum1(ve[i].id,ve[i].club);
				a[ve[i].id].is=1;
			}
		}
		if (ve[i].club==3) {
			if (cntz<n/2) {
				cntz++;
				ans+=getnum1(ve[i].id,ve[i].club);
				a[ve[i].id].is=1;
			}
		}
	}
	ve.clear();
	for (int i=1;i<=n;i++) {
		if (a[i].is) continue; 
		if (a[i].x>=max(a[i].y,a[i].z)&&cntx<n/2) {
			ve.push_back({i,1});
		}else if (a[i].y>=max(a[i].x,a[i].z)&&cnty<n/2) {
			ve.push_back({i,2});
		}else if (cntz<n/2) {
			ve.push_back({i,3});
		}
	}
	sort(ve.begin(),ve.end(),cmp1);
	for (int i=0;i<ve.size();i++) {
		if (ve[i].club==1) {
			if (cntx<n/2) {
				cntx++;
				ans+=getnum1(ve[i].id,ve[i].club);
				a[ve[i].id].is=1;
			}
		}
		if (ve[i].club==2) {
			if (cnty<n/2) {
				cnty++;
				ans+=getnum1(ve[i].id,ve[i].club);
				a[ve[i].id].is=1;
			}
		}
		if (ve[i].club==3) {
			if (cntz<n/2) {
				cntz++;
				ans+=getnum1(ve[i].id,ve[i].club);
				a[ve[i].id].is=1;
			}
		}
	}
	for (int i=1;i<=n;i++) {
		if (a[i].is) continue; 
		if (cntx<n/2) {
			ans+=a[i].x;
			cntx++;
		}else if (cnty<n/2) {
			ans+=a[i].y;
			cnty++;
		}else if (cntz<n/2) {
			ans+=a[i].z;
			cntz++;
		}
	}
	printf("%d\n",ans);
}
//////////////////


//////////////////
/*
3
2
10 9 8
4 0 0
*/
int f[105][105][105];
void solve2() {//n<=200 
	for (int j=n/2;j>=0;j--) {
		for (int k=n/2;k>=0;k--) {
			for (int l=n/2;l>=0;l--) {
				f[j][k][l]=-1;
			}
		}
	}
	f[0][0][0]=0;
	for (int i=1;i<=n;i++) {
		for (int j=n/2;j>=0;j--) {
			for (int k=n/2;k>=0;k--) {
				for (int l=n/2;l>=0;l--) {
					if (f[j][k][l]==-1) continue;
					if (j<n/2) f[j+1][k][l]=max(f[j+1][k][l],f[j][k][l]+a[i].x);
					if (k<n/2) f[j][k+1][l]=max(f[j][k+1][l],f[j][k][l]+a[i].y);
					if (l<n/2) f[j][k][l+1]=max(f[j][k][l+1],f[j][k][l]+a[i].z);
				}
			}
		}
	}
	int ans=0;
	for (int j=n/2;j>=0;j--) {
		for (int k=n/2;k>=0;k--) {
			for (int l=n/2;l>=0;l--) {
				ans=max(ans,f[j][k][l]);
			}
		}
	}
	printf("%d\n",ans);
}
//////////////////
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			a[i].is=0;
		}
		if (n<=200) {
			solve2();
		}else {
			solve1();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
