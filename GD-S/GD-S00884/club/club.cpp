#include<bits/stdc++.h>
using namespace std;

int t, c1[100001], c2[100001], c3[100001], t1, t2, t3;
struct people{
	int x, y, z, s;
}a[100001];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for( ; t--; ){
		t1 = t2 = t3 = 0;
		int n;
		long long sum = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		for(int i = 1; i <= n; i++){
			if(a[i].x >= a[i].y && a[i].x >= a[i].z){
				sum += a[i].x;
				if(a[i].y >= a[i].z)
					a[i].s = a[i].x - a[i].y;
				else
					a[i].s = a[i].x - a[i].z;
				c1[++t1] = a[i].s;
			}
			else
				if(a[i].y >= a[i].x && a[i].y >= a[i].z){
					sum += a[i].y;
					if(a[i].x >= a[i].z)
						a[i].s = a[i].y - a[i].x;
					else
						a[i].s = a[i].y - a[i].z;
					c2[++t2] = a[i].s;
				}
				else
					if(a[i].z >= a[i].y && a[i].z >= a[i].x){
						sum += a[i].z;
						if(a[i].y >= a[i].x)
							a[i].s = a[i].z - a[i].y;
						else
							a[i].s = a[i].z - a[i].x;
						c3[++t3] = a[i].s;
					}
		}
		if(t1 > n / 2){
			sort(c1 + 1, c1 + t1 + 1);
			for(int i = 1; i <= t1 - n / 2; i++)
				sum -= c1[i];
		}
		else
			if(t2 > n / 2){
				sort(c2 + 1, c2 + t2 + 1);
				for(int i = 1; i <= t2 - n / 2; i++)
					sum -= c2[i];
			}
			else
				if(t3 > n / 2){
					sort(c3 + 1, c3 + t3 + 1);
					for(int i = 1; i <= t3 - n / 2; i++)
						sum -= c3[i];
				}
		printf("%lld\n", sum);
	}
	return 0;
}
