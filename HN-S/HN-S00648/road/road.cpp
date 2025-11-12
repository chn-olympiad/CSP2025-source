#include<bits/stdc++.h>
#define ll long long
#define f(i,n,m) for(int i = n; i <= m; i++)
using namespace std;
const ll N = 1e4+1;
ll rd(){
	ll x, f = 1;
	char s;
	s = getchar();
	if(s == '-') f = -1, x = 0;
	else x=s-'0';
	while(1){
		s = getchar();
		if(s < '0' || s > '9') return x*f;
		x*=10, x+=s-'0';
	}
}
struct st{
	int x, y, u;
};
bool operator < (st a, st b){
	return a.u < b.u;
}
int n, m, k, ded = 0, f[N], w[11], t[11], b = 0;
st q[1100010];
int find(int x){
	if(x == f[x]) return x;
	return x = f[x];
}
int ke(){
	ll ded = 0;
	for(int i = 1; i <= b; i++){
		if(find(q[i].x) == find(q[i].y)) continue;
		f[f[q[i].x]] = f[q[i].y];
		ded+=q[i].u;
		if(q[i].x > n) t[q[i].x-n]++;
		f(j,1,n)
			if(find(f[j]) != find(f[1])) break;
			else if(j == n) return ded;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x, y, z;
	n = rd(), m = rd(), k = rd();
	while(m--)
		x = rd(),
		y = rd(),
		z = rd(),
		b++, q[b] = st{x,y,z};
	f(i,1,k){
		w[i] = rd();
		f(j,1,n)
			y = rd(),
			b++,q[b] = st{i+n,j,y+w[i]};
	}
	sort(q+1,q+b+1);
	memset(t,0,sizeof t);
	f(i,1,n+k) f[i] = i;
	int d = ke();
	for(int i = 1; i <= k; i++) if(t[i])d-=(t[i]-1)*w[i];
	cout << d;
	return 0;
}
