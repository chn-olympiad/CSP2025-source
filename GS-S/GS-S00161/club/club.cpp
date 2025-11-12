#include <bits/stdc++.h>
using namespace std;
long long m,n[6],a[10005],b[10005],c[10005],d[10005],e[4],f[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> m;
	for (long long i = 1;i <= m;i++){
		cin >> n[i];
		long long t = 0;
		for (long long j = 1;j <= n[i];j++){
			scanf("%lld%lld%lld",&a[j],&b[j],&c[j]);
			e[1] = a[j],e[2] = b[j],e[3] = c[j];
			sort(e + 1,e + 3 + 1);
			if (a[j] == e[3]){d[j] = 1;}
			if (b[j] == e[3]){d[j] = 2;}
			if (c[j] == e[3]){d[j] = 3;}
		}
		sort(d + 1,d + n[i] + 1);
		for(long long j = 1;j <= n[i];j += 2){
			if (d[j] == d[j + 1] && d[j] == 1){
				if (a[j] > a[j + 1]){t += a[j];t += max(b[j + 1],c[j + 1]);}
				else
					if (a[j] == a[j + 1]){
						t += a[j];
						long long p = max(b[j],c[j]);
						long long q = max(b[j + 1],c[j + 1]);
						t += max(p,q);
					}
					else{
						t += a[j + 1];
						t += max(b[j],c[j]);						
					}
			}
			else if (d[j] == d[j + 1] && d[j] == 2){
					 if (b[j] > b[j + 1]){t += b[j];t += max(a[j + 1],c[j + 1]);}
					 else
						 if (b[j] == b[j + 1]){
							 t += b[j];
							 long long p = max(a[j],c[j]);
							 long long q = max(a[j + 1],c[j + 1]);
							 t += max(p,q);
						 }
						 else{
							 t += b[j + 1];
							 t += max(a[j],c[j]);
							 }
				 }
			else if (d[j] == d[j + 1] && d[j] == 3){
					 if (c[j] > c[j + 1]){t += c[j];t += max(b[j + 1],a[j + 1]);}
					 else
						 if (c[j] == c[j + 1]){
							 t += c[j];
							 long long p = max(b[j],a[j]);
							 long long q = max(b[j + 1],a[j + 1]);
							 t += max(p,q);
						 }
						 else{
							 t += c[j + 1];
							 t += max(b[j],a[j]);						 	
						 }
				 }
			if(d[j] != d[j + 1]){
				e[1] = a[j],e[2] = b[j],e[3] = c[j];
				sort(e + 1,e + 3 + 1);
				t += e[3];
				f[1] = a[j + 1],f[2] = b[j + 1],f[3] = c[j + 1];
				sort(f + 1,f + 3 + 1);
				t += f[3];
			}
		}
		printf("%lld\n",t);
	}
	return 0;
}
