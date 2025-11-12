#include<bits/stdc++.h>
using namespace std;
struct node {
	bool f;
	bool k=0;
};
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	cin >>n>>k;
	node f[n+10];
	for(int i=1; i<=n; i++)cin >>f[i].f;
	if(k==0) {
		bool l=0;
		for(int i=1; i<=n; i++) {
			if(f[i].f>=1) {
				l=1;
			}
		}
		if(l==1) {
			for(int i=1; i<=n; i++) {
				if(f[i].f==0) {
					s++;
				}
				if(f[i].f==1) {
					if(f[i].f==f[i+1].f&&f[i].k==0&&f[i+1].k==0) {
						f[i].k=1;
						f[i+1].k=1;
						s++;
					}
				}
			}
		} else {
			cout <<n/2;
			return 0;
		}
	}
	if(k==1) {
		long long s=0;
		for(int i=1; i<=n; i++) {
			if(f[i].k==1)continue;
			if(f[i].f!=f[i+1].f&&f[i+1].k==0) {
				f[i+1].k=1;
				f[i].k=1;
				s++;
			}
		}
	}
	cout <<s;
	return 0;
}

