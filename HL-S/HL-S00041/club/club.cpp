#include <bits/stdc++.h>
using namespace std;
int t;
struct mber{
	int a,b,c,fir,sec,tir;
};
int main(){
	freopen("F:\\club\\club.in","r",stdin);
	freopen("F:\\club\\club.out","w",stdout);
	cin >> t;
	while(t--) {
		int n,am=0,bm=0,cm=0,sum=0;
		struct mber m[1145];
		cin >> n;
		for (int i=0;i<n;i++) cin >> m[i].a >> m[i].b >> m[i].c;
		for (int i=0;i<n;i++) {
			m[i].fir=max(m[i].a,max(m[i].b,m[i].c));
			m[i].tir=min(m[i].a,min(m[i].b,m[i].c));
			m[i].sec=m[i].a+m[i].b+m[i].c-m[i].fir-m[i].tir;
		}
		for (int i=0;i<n;i++) {
			if (m[i].fir==m[i].a) {
				am++;
				sum+=m[i].fir;
			}
			if (m[i].fir==m[i].b) {
				bm++;
				sum+=m[i].fir;
			}
			if (m[i].fir==m[i].c) {
				cm++;
				sum+=m[i].fir;
			}
		}
		cout << sum << endl;
	}
}