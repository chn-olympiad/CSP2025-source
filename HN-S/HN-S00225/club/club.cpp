#include <bits/stdc++.h>
using namespace std;
const int NR = 1e5 + 5;
int t, n, c[5], ans, pos;
struct stu{
	int a, b, c, id, maxd, ma, mi, maid, miid, maxid;
}d[NR];
bool cmp(stu x, stu y){
	if(x.mi == y.mi){
		if(x.maxd == y.maxd)return x.ma > y.ma;
		return x.maxd < y.maxd;
	}
	return x.mi < y.mi;
}
void init(){
	pos = ans = 0;
	c[1] = c[2] = c[3] = 0; 
}
int main(){
  	freopen("club.in","r",stdin);
  	freopen("club.out","w",stdout);
	cin >> t;
	while(t --){
		cin >> n;
		init();
		for(int i = 1;i <= n;i ++){
			cin >> d[i].a >> d[i].b >> d[i].c;
			d[i].id = i;
			d[i].ma = max(d[i].a, max(d[i].b, d[i].c));
			if(d[i].a == d[i].ma){
				if(d[i].b > d[i].c){
					d[i].maxd = d[i].b;
					d[i].maxid = 2;
					d[i].mi = d[i].c;
					d[i].miid = 3;
				}
				else{
					d[i].maxd = d[i].c;
					d[i].maxid = 3;
					d[i].mi = d[i].b;
					d[i].miid = 2;
				}
				d[i].maid = 1;
			}
			else if(d[i].b == d[i].ma){
				if(d[i].a > d[i].c){
					d[i].maxd = d[i].a;
					d[i].maxid = 1;
					d[i].mi = d[i].c;
					d[i].miid = 3;
				}
				else{
					d[i].maxd = d[i].c;
					d[i].maxid = 3;
					d[i].mi = d[i].a;
					d[i].miid = 1;
				}
				d[i].maid = 2;
			}
			else {
				if(d[i].a > d[i].b){
					d[i].maxd = d[i].a;
					d[i].maxid = 1;
					d[i].mi = d[i].b;
					d[i].miid = 2;
				}
				else{
					d[i].maxd = d[i].b;
					d[i].maxid = 2;
					d[i].mi = d[i].a;
					d[i].miid = 1;
				}
				d[i].maid = 3;
			}
		}
		sort(d + 1, d + n + 1, cmp);
		for(int i = 1;i <= n;i ++){
			ans += d[i].ma;
			c[d[i].maid] ++;
			d[i].ma = d[i].maxd = d[i].mi = 0;
			if(c[d[i].maid] == n / 2){
				pos = i;
				break;
			}
		}
		if(c[1] + c[2] + c[3] == n){
			cout << ans << '\n';
			continue;
		}
		if(c[1] == n / 2){
			for(int i = pos + 1;i <= n;i ++){
				d[i].a = 0;
				d[i].ma = max(d[i].b, d[i].c);
				if(d[i].b == d[i].ma){
					d[i].maxd = d[i].c;
				}
				else {
					d[i].maxd = d[i].b;
				}
				d[i].mi = 0;
			}
			sort(d + 1, d + n + 1, cmp);
			for(int i = 1;i <= n;i ++)ans += d[i].ma;
		}
		if(c[2] == n / 2){
			for(int i = pos + 1;i <= n;i ++){
				d[i].b = 0;
				d[i].ma = max(d[i].a, d[i].c);
				if(d[i].a == d[i].ma){
					d[i].maxd = d[i].c;
				}
				else {
					d[i].maxd = d[i].a;
				}
				d[i].mi = 0;
			}
			sort(d + 1, d + n + 1, cmp);
			for(int i = 1;i <= n;i ++)ans += d[i].ma;
		}
		if(c[3] == n / 2){
			for(int i = pos + 1;i <= n;i ++){
				d[i].a = 0;
				d[i].ma = max(d[i].a, d[i].b);
				if(d[i].a == d[i].ma){
					d[i].maxd = d[i].b;
				}
				else {
					d[i].maxd = d[i].a;
				}
				d[i].mi = 0;
			}
			sort(d + 1, d + n + 1, cmp);
			for(int i = 1;i <= n;i ++)ans += d[i].ma;
		}
		cout << ans << '\n';
	}
	return 0;
}
