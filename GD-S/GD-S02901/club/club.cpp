#include<bits/stdc++.h>
using namespace std ;
const int maxn=1e5+5;
int n;
struct node {
	int a,b,c,go;
	void input () {
		cin>>a>>b>>c;
	}
	void init () {
		a=0;
		b=0;
		c=0;
	}
	void debug () {
		cout<<a<<' '<<b<<' '<<c<<' '<<go<<"\n";
	}
}a[maxn];
bool cmp1 (node a,node b) {
	return a.a>b.a;
}
bool cmp2 (node a,node b) {
	if (a.a==b.a) {
		return a.b<b.b;
	}
	return a.a>b.a;
}
bool cmp3 (node a,node b) {
	if (a.a==b.a) {
		if (a.b==b.b) return a.c<b.c;
		return a.b<b.b;
	}
	return a.a>b.a;
}
int main () {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for (;t--;cout<<"\n"){
		for (int i=1;i<maxn;i++) {
			a[i].init(); 
		}
		int ans=0;
		cin>>n;
		for (int i=1;i<=n;i++) {
			a[i].input(); 
		}
		bool flagA=0,flagB=0; //特殊性质特殊做
		bool flag1=1,flag2=1,flag3=1;
		for (int i=1;i<=n;i++) {
			if (a[i].a!=0) flag1=0;
			if (a[i].b!=0) flag2=0;
			if (a[i].c!=0) flag3=0;
		}
		if (flag1&&flag2) {
			flagA=1;
			for (int i=1;i<=n;i++) {
				swap(a[i].a,a[i].c);
			}
		}
		if (flag1&&flag3) {
			flagA=1;
			for (int i=1;i<=n;i++) {
				swap(a[i].a,a[i].b);
			}
		}
		if (flag2&&flag3) {
			flagA=1;
		}
		if (flag1&&!flagA) {
			flagB=1;
			for (int i=1;i<=n;i++) {
				swap(a[i].a,a[i].c);
			}
		}
		if (flag2&&!flagA) {
			flagB=1;
			for (int i=1;i<=n;i++) {
				swap(a[i].b,a[i].c);
			}
		}
		if (flag3&&!flagA) {
			flagB=1;
		}
		//for (int i=1;i<=n;i++) a[i].debug();
		if (flagA) { //特殊性质 A 
			sort(a+1,a+1+n,cmp1);
			for (int i=1;i<=n/2;i++) {
				ans+=a[i].a;
			}
			cout<<ans;
			continue;
		}
		else if (flagB) { // 特殊性质 B
			int goA=0,goB=0;
			for (int i=1;i<=n;i++) {
				if (a[i].a>a[i].b) {
					a[i].go=1;
				}
				else {
					a[i].go=2;
				}
			}
			sort(a+1,a+1+n,cmp2);
			for (int i=1;i<=n;i++) {
				if (a[i].go==1&&goA<n/2) {
					goA++;
					ans+=a[i].a;
				}
				if (a[i].go==1&&goA>n/2) {
					goB++;
					ans+=a[i].b;
				}
				if (a[i].go==2&&goB<n/2) {
					goB++;
					ans+=a[i].b;
				}
				if (a[i].go==2&&goB>n/2) {
					goA++;
					ans+=a[i].a;
				}
			}
			cout<<ans;
		}  
		else {
			int goA=0,goB=0,goC=0;
			for (int i=1;i<=n;i++) {
				int tmp=max({a[i].a,a[i].b,a[i].c});
				if (tmp==a[i].a) {
					a[i].go=1;
				}
				else if (tmp==a[i].b){
					a[i].go=2;
				}
				else {
					a[i].go=3;
				}
			}
			sort(a+1,a+1+n,cmp3);
			for (int i=1;i<=n;i++) {
				if (a[i].go==3&&goC<n/2) {
					goC++;
					ans+=a[i].c;
				}
				if (a[i].go==2&&goB<n/2) {
					goB++;
					ans+=a[i].b;
				}
				if (a[i].go==1&&goA<n/2) {
					goA++;
					ans+=a[i].a;
				}
				if (a[i].go==1&&goA>n/2) {
					if (a[i].b>a[i].c&&goB<=n/2) {
						goB++;
						ans+=a[i].b;
					}
					else if (goB>n/2) {
						goC++;
						ans+=a[i].c;
					}
					else if (goC>n/2) {
						goB++;
						ans+=a[i].b;
					}
				}
				if (a[i].go==2&&goB>n/2) {
					if (a[i].a>a[i].c&&goA<=n/2) {
						goA++;
						ans+=a[i].a;
					}
					else if (goA>n/2) {
						goC++;
						ans+=a[i].c;
					}
					else if (goB>n/2) {
						goC++;
						ans+=a[i].c;
					}
				}
				if (a[i].go==3&&goC>n/2) {
					if (a[i].a>a[i].c&&goA<=n/2) {
						goA++;
						ans+=a[i].a;
					}
					else if (goA>n/2) {
						goB++;
						ans+=a[i].b;
					}
					else if (goC>n/2) {
						goB++;
						ans+=a[i].b;
					}
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
/*
1
4
4 5 0
5 4 0
2 9 0
7 3 0
*/
