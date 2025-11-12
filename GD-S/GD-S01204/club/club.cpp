#include<bits/stdc++.h>
using namespace std;
const int qwq = 1e6 + 10;
struct node {
	int num;
} a[qwq];
node b[qwq],c[qwq];
int t;
int id,id1,id2;
int k;
bool v[qwq];
bool cmp(node x,node y) {
	return x.num > y.num;
}
int f(int x) {
	int cnt = 0;
	sort(a+1,a+1+x,cmp);
	for(int i = 1; i <= x/2; i++) {
		cnt += a[i].num;
	}
	return cnt;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t; 
	while(t--) {
		int n;
		int id = id1 = id2 = 0;
		int cnt = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i = 1; i <= n; i++) {
			cin>>a[i].num>>b[i].num>>c[i].num;
			if(b[i].num == 0 && c[i].num == 0)
				k+=2;
		}
		if(k == 2*n) {
			cout<<f(n)<<endl;
			continue;
		}
		for(int i = 1; i <= n; i++) {
			if(a[i].num > b[i].num && a[i].num > c[i].num && id <= (n/2)) { //a>b>c
				id++;
				cnt += a[i].num;
			} else if(a[i].num > b[i].num && a[i].num < c[i].num && id2 <= (n/2)) { //c>a>b
				id2++;
				cnt+=c[i].num;
			} else if(a[i].num < b[i].num && a[i].num < c[i].num && id1 <=(n/2)) { //b>c>a
				id1++;
				cnt += b[i].num;
			} else if(a[i].num < b[i].num && b[i].num < c[i].num && id2 <= (n/2)) { //c>b>a
				id2++;
				cnt += c[i].num;
			} else if(a[i].num > c[i].num && c[i].num > b[i].num && id <= (n/2)) { //a>c>b
				id++;
				cnt += a[i].num;
			} else if(b[i].num > a[i].num && a[i].num > c[i].num && id1 <= (n/2)) { //b>a>c
				id1++;
				cnt += b[i].num;
			}
			if(a[i].num > b[i].num && a[i].num < c[i].num && id2 > (n/2)) { //c>a>b
				if(id <= (n/2)) {
					id++;
					cnt+=a[i].num;
				} else {
					id1++;
					cnt+=b[i].num;
				}
			} else if(a[i].num > b[i].num && a[i].num > c[i].num && id > (n/2)) { //a>b>c
				if(id1 <= (n/2)) {
					id1++;
					cnt+=b[i].num;
				} else {
					id1++;
					cnt+=c[i].num;
				}
			} else if(a[i].num < b[i].num && a[i].num < c[i].num && id1 > (n/2)) { //b>c>a
				if(id2 <= (n/2)) {
					id2++;
					cnt+=c[i].num;
				} else {
					id++;
					cnt+=a[i].num;
				}
			} else if(a[i].num < b[i].num && b[i].num < c[i].num && id2 > (n/2)) { //c>b>a
				if(id1 <= (n/2)) {
					id1++;
					cnt+=b[i].num;
				} else {
					id++;
					cnt+=a[i].num;
				}
			} else if(a[i].num > c[i].num && c[i].num > b[i].num && id > (n/2)) { //a>c>b
				if(id2 <= (n/2)) {
					id2++;
					cnt+=c[i].num;
				} else {
					id1++;
					cnt+=b[i].num;
				}
			} else if(b[i].num > a[i].num && a[i].num > c[i].num && id1 > (n/2)) { //b>a>c
				if(id <= (n/2)) {
					id++;
					cnt+=a[i].num;
				} else {
					id2++;
					cnt+=c[i].num;
				}
			}
//			cout<<id<<" "<<id1<<" "<<id2<<endl;
//			cout<<cnt<<endl;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
