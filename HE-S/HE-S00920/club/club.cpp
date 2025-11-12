#include <bits/stdc++.h>
using namespace std;
int t,n,a[100000],b[100000], c[100000];
int xx,yy,zz,cnt,xxx,yyy,zzz,abc;
int d[100000],e[100000],f[10000],s[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		for(int j = 1;j <= n;j++){
			cin >> a[j] >> b[j] >> c[j];
			d[j] = a[j];
			e[j] = b[j];
			f[j] = c[j];
			abc = 0;
		}
		for(int k = 1;k <= n;k++){
			if(max(a[k],max(b[k],c[k])) == a[k]){
				xx++;
				xxx += a[k];
			}
			if(max(a[k],max(b[k],c[k])) == b[k]){
				yy++;
				yyy += b[k]; 
			}
			if(max(a[k],max(b[k],c[k])) == c[k]){
				zz++;
				zzz += c[k];
			}
			abc += xxx+yyy+zzz;
			xxx = 0;
			yyy = 0;
			zzz = 0;
		}
		while(xx > n/2){
			for(int h = 1;h <= n;h++){
				s[h] = d[h]-max(e[h],f[h]);
			}
			sort(s+1,s+1+n);
			abc -= s[1];
			xx--;
		}
		while(yy > n/2){
			for(int h = 1;h <= n;h++){
				s[h] = e[h]-max(d[h],f[h]);
			}
			sort(s+1,s+1+n);
			abc -= s[1];
			yy--;
		}
		while(zz > n/2){
			for(int h = 1;h <= n;h++){
				s[h] = f[h]-max(e[h],d[h]);
			}
			sort(s+1,s+1+n);
			abc -= s[1];
			zz--;
		}
		cout << abc;
		zz = 0;
		yy = 0;
		xx = 0;
	}
	return 0;
} 
