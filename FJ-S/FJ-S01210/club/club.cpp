#include<bits/stdc++.h>
using namespace std;
long long q, n;
struct Edge{
	int i, n;
}a[100001],b[100001],c[100001];
bool cmp(Edge x,Edge y){
	return x.n > y.n;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> q;
	while(q--){
		long long k, ans = 0, p1 = 1, p2 = 1, p3 = 1, k1 = 0, k2 = 0, k3 = 0;
		bool v[100001];
		for(register int i = 1; i <= 100001; i++){
			v[i] = 0;
		}
		cin >> n;
		k = n / 2;
		for(int i = 1; i <= n; i++){
			scanf("%lld%lld%lld",&a[i].n,&b[i].n,&c[i].n);
			a[i].i = i;
			b[i].i = i;
			c[i].i = i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		while(k1 + k2 + k3 < n){
			if(max(a[p1].n,max(b[p2].n,c[p3].n)) == a[p1].n && p1 <= n){
				if(v[a[p1].i] == 0 && k1 < k){
					k1++;
					v[a[p1].i] = 1;
					ans += a[p1].n;
				}
				p1++;
			}
			if(max(a[p1].n,max(b[p2].n,c[p3].n)) == b[p2].n && p2 <= n){
				if(v[b[p2].i] == 0 && k2 < k){
					k2++;
					v[b[p2].i] = 1;
					ans += b[p2].n;
				}
				p2++;
			}
			if(max(a[p1].n,max(b[p2].n,c[p3].n)) == c[p3].n && p3 <= n){
				if(v[c[p3].i] == 0 && k3 < k){
					k3++;
					v[c[p3].i] = 1;
					ans += c[p3].n;
				}
				p3++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
