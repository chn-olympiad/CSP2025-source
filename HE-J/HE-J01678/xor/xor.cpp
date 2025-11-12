#include <bits/stdc++.h>
using namespace std;
long long n, k, p, sum, last = 1, now;
long long a[500005];
struct node{
	int l, r;
}s[500005];
long long yh(long long x, long long y){
	long long nx = x, ny = y, i = 0, j = 0, ans = 0;
	int q[25], w[25];
	while(nx != 1 && nx != 0){
		q[i] = nx % 2;
		i++;
		nx /= 2;
	}
	q[i] = nx;
	while(ny != 1 && ny != 0){
		w[j] = ny % 2;
		j++;
		ny /= 2;
	}
	w[j] = ny;
	if(i >= j){
		while(i >= 0){
			if(q[i] != w[i]){
				ans += pow(2, i);
			}
			i--;
		}
		return ans;
	}else{
		while(j >= 0){
			if(q[j] != w[j]){
				ans += pow(2, j);
			}
			j--;
		}
		return ans;
	}
}
bool cmp(node g, node d){
	if(g.l == d.l){
		return g.r < d.r;
	}
	return g.l < d.l;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == k){
			s[p].l = i;
		    s[p].r = i;
			p++;
		}
	}
	for(int i = 1; i <= n; i++){
		sum = a[i];
		for(int j = i + 1; j <= n; j++){
			sum = yh(sum, a[j]);
			if(sum == k){
				s[p].l = i;
				s[p].r = j;
				p++;
			}
		}
	}
	p--;
	if(s[0].l == 0){
		cout << 0;
		return 0;
	}
	sort(s, s + p, cmp);
	now = s[0].r;
	for(int i = 1; i <= p; i++){
		if(s[i].l > now){
			now = s[i].r;
			last++;
		}
	}
	cout << last;
	return 0;
}
