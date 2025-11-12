#include<bits/stdc++.h>
#define ll long long
#define f(i,n,m) for(int i = n; i <= m; i++)
#define fe(i,n,m) for(int i = n; i >= m; i--)
using namespace std;
const ll N = 1e5+1;
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
	int x, id;
};
bool operator < (st a, st b){
	if(a.x == b.x) return a.id < b.id;
	return a.x < b.x;
}
ll n, ded;
st a[N][4];
int b[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = rd();
	while(t--){
		n = rd();
		memset(b,0,sizeof b);
		ded = 0;
		f(i,1,n)
			f(j,1,3)
				a[i][j].x = rd(), a[i][j].id = j; 
		f(i,1,n)
			sort(a[i]+1,a[i]+4);
		f(i,1,n)
			fe(j,3,1){
				if(b[a[i][j].id] > n/2) continue;
				b[a[i][j].id]++;
				ded+=a[i][j].x;
				break;
			}
		printf("%lld\n", ded);
	}
	return 0;
}
