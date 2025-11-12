#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}
inline void write(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
	return;
}
struct datas {
	int sum, id;
} aa[100005], bb[100005], cc[100005];
int n, t, a[100005][5], ac, ak, rp, csp[100005];
bool cmp(datas x, datas y) {
	return x.sum > y.sum;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t = read();
	while (t--) {
		int ans=0,ac=0,ak=0,rp=0;
		n = read();
		for (int i = 1; i <= n; i++) {
			a[i][1] = read();
			a[i][2] = read();
			a[i][3] = read();
			int maxx = max({a[i][1], a[i][2], a[i][3]});
			if (maxx==a[i][1]) {
				ac++;
				aa[ac].sum = maxx;
				aa[ac].id = i;
			} else if (maxx==a[i][2]) {
				ak++;
				bb[ak].sum = maxx;
				bb[ak].id = i;
			} else {
				rp++;
				cc[rp].sum = maxx;
				cc[rp].id = i;
			}
		}
		sort(aa + 1, aa + ac + 1, cmp);
		sort(bb + 1, bb + ak + 1, cmp);
		sort(cc + 1, cc + rp + 1, cmp);
//		for(int i=1;i<=ac;i++) write(aa[i].sum);
//		printf("\n");
//		for(int i=1;i<=ak;i++) write(bb[i].sum);
//		printf("\n");
//		for(int i=1;i<=rp;i++) write(cc[i].sum);
//		printf("\n");
		if (ac > n / 2) {
			while(ac>n/2){
				int maxx=INT_MIN,p,kkk=0,p2;
				for(int i=1;i<=ac;i++) kkk+=aa[i].sum;
				for(int i=1;i<=ak;i++) kkk+=bb[i].sum;
				for(int i=1;i<=rp;i++) kkk+=cc[i].sum;
				for(int i=1;i<=ac;i++){
					if(a[aa[i].id][2] > a[aa[i].id][3]){
						if(maxx<kkk-a[aa[i].id][1]+a[aa[i].id][2]){
							maxx=kkk-a[aa[i].id][1]+a[aa[i].id][2];
							p=i;
							p2=1;
						}
					}else{
						if(maxx<kkk-a[aa[i].id][1]+a[aa[i].id][3]){
							maxx=kkk-a[aa[i].id][1]+a[aa[i].id][3];
							p=i;
							p2=2;
						}
					}
				}
				if(p2==1){
					bb[++ak].sum=a[aa[p].id][2];
				}else{
					cc[++rp].sum=a[aa[p].id][3];
				}
				int ac2=0,pp[100005];
				for(int i=1;i<=ac;i++){
					if(aa[i].sum!=a[aa[p].id][1]) pp[++ac2]=aa[i].sum; 
				}
				for(int i=1;i<=ac2;i++) aa[i].sum=pp[i];
				ac--;
			}
		}else if(ak>n/2){
			while(ak>n/2){
				int maxx=INT_MIN,p,kkk=0,p2;
				for(int i=1;i<=ac;i++) kkk+=aa[i].sum;
				for(int i=1;i<=ak;i++) kkk+=bb[i].sum;
				for(int i=1;i<=rp;i++) kkk+=cc[i].sum;
				for(int i=1;i<=ak;i++){
					if(a[cc[i].id][1] > a[cc[i].id][3]){
						if(maxx<kkk-a[cc[i].id][2]+a[cc[i].id][1]){
							maxx=kkk-a[cc[i].id][2]+a[cc[i].id][1];
							p=i;
							p2=1;
						}
					}else{
						if(maxx<kkk-a[cc[i].id][2]+a[cc[i].id][3]){
							maxx=kkk-a[cc[i].id][2]+a[cc[i].id][3];
							p=i;
							p2=2;
						}
					}	
				}
				if(p2==1){
					aa[++ac].sum=a[bb[p].id][1];
				}else{
					cc[++rp].sum=a[bb[p].id][3];
				}
				int ac2=0,pp[100005];
				for(int i=1;i<=ak;i++){
					if(bb[i].sum!=a[bb[p].id][2]) pp[++ac2]=bb[i].sum; 
				}
				for(int i=1;i<=ac2;i++) bb[i].sum=pp[i];
				ak--;
			}
		}else{
			while(rp>n/2){
				int maxx=INT_MIN,p,kkk=0,p2;
				for(int i=1;i<=ac;i++) kkk+=aa[i].sum;
				for(int i=1;i<=ak;i++) kkk+=bb[i].sum;
				for(int i=1;i<=rp;i++) kkk+=cc[i].sum;
				for(int i=1;i<=rp;i++){
					if(a[cc[i].id][1] > a[cc[i].id][2]){
						if(maxx<kkk-a[cc[i].id][3]+a[cc[i].id][1]){
							maxx=kkk-a[cc[i].id][3]+a[cc[i].id][1];
							p=i;
							p2=1;
						}
					}else{
						if(maxx<kkk-a[cc[i].id][3]+a[cc[i].id][2]){
							maxx=kkk-a[cc[i].id][3]+a[cc[i].id][2];
							p=i;
							p2=2;
						}
					}
				}
				if(p2==1){
					aa[++ac].sum=a[cc[p].id][1];
				}else{
					cc[++ak].sum=a[cc[p].id][2];
				}
				int ac2=0,pp[100005];
				for(int i=1;i<=rp;i++){
					if(aa[i].sum!=a[aa[p].id][1]) pp[++ac2]=aa[i].sum; 
				}
				for(int i=1;i<=ac2;i++) aa[i].sum=pp[i];
				rp--;
			}
			
		}
		for(int i=1;i<=ac;i++) ans+=aa[i].sum;
		for(int i=1;i<=ak;i++) ans+=bb[i].sum;
		for(int i=1;i<=rp;i++) ans+=cc[i].sum;
//		for(int i=1;i<=ac;i++) write(aa[i].sum);
//		printf("\n");
//		for(int i=1;i<=ak;i++) write(bb[i].sum);
//		printf("\n");
//		for(int i=1;i<=rp;i++) write(cc[i].sum);
//		printf("\n\n");
		write(ans);
		printf("\n");
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
