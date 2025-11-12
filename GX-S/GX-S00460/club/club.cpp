#include <iostream>
#include <algorithm>
using namespace std;

struct person{
	int d;
	int c;
};

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	for(int TT = 0; TT < T; TT++){
		int n;
		cin >> n;
		int a[n], b[n], c[n], ca = 0, cb = 0, cc = 0;
		person p[n];
		int ans = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i] >> b[i] >> c[i];
			int tmp1, tmp2, tmpd;
			if(a[i] > b[i])tmp1 = a[i], tmp2 = b[i], tmpd = 1;
			else tmp1 = b[i], tmp2 = a[i], tmpd = 2;
			if(c[i] > tmp1)p[i].d = 3, p[i].c = c[i]-tmp1, cc++, ans += c[i];
			else{
				if(c[i] > tmp2)p[i].d = tmpd, p[i].c = tmp1-c[i];
				else p[i].d = tmpd, p[i].c = tmp1-tmp2;
			}
			if(p[i].d == 1)ca++, ans += a[i];
			else if(p[i].d == 2)cb++, ans += b[i];
		}
		int cha[n], pc = 0;
		if(ca > n/2){
			for(int i = 0; i < n; i++)if(p[i].d == 1)cha[pc++] = p[i].c;
			sort(cha, cha+pc);
			int times = ca - (n/2);
			for(int i = 0; i < times; i++)ans -= cha[i];
		}
		else if(cb > n/2){
			for(int i = 0; i < n; i++)if(p[i].d == 2)cha[pc++] = p[i].c;
			sort(cha, cha+pc);
			int times = cb - (n/2);
			for(int i = 0; i < times; i++)ans -= cha[i];
		}
		else if(cc > n/2){
			for(int i = 0; i < n; i++)if(p[i].d == 3)cha[pc++] = p[i].c;
			sort(cha, cha+pc);
			int times = cc - (n/2);
			for(int i = 0; i < times; i++)ans -= cha[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
