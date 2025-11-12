#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t,n, f[510][510][510];

struct T{
	ll a,b,c;
}A[100100];

bool cmp(T x,T y){
	if(x.a-x.b == y.a-y.b) return x.c > y.c;
	return x.a-x.b > y.a-y.b;
}

ll Get(ll x, ll i){
	ll tmp = 0;
	if(i == 1) tmp += A[x].a;
	else if(i == 2) tmp += A[x].b;
	else tmp += A[x].c;
	return tmp;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		ll ans = 0, _n;
		
		cin>>n;
		_n = n/2;
		for(int i=1;i<=n;++i){
			cin>>A[i].a>>A[i].b>>A[i].c;
		}
		
		if(n == 2){
			for(int i=1;i<=3;++i){
				for(int j=1;j<=3;++j){
					if(i == j) continue;
					
					ll tmp = Get(1,i) + Get(2,j);
					
					ans = max(ans, tmp);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		if(n == 4){
			for(int i=1;i<=3;++i){
				for(int j=1;j<=3;++j){
					for(int k=1;k<=3;++k){
						for(int ii=1;ii<=3;++ii){
//							if(i == j || i == k || i == ii || j == k || j == ii || k == ii) continue;
							
							ll cnt = (i == j) + (i == k) + (i == ii);
							if(cnt > 1) continue;
							cnt = (j == i) + (j == k) + (j == ii);
							if(cnt > 1) continue;
							cnt = (k == i) + (k == j) + (k == ii);
							if(cnt > 1) continue;
							cnt = (ii == i) + (ii == j) + (ii == k);
							if(cnt > 1) continue;
							
							ll tmp = Get(1,i) + Get(2,j) + Get(3,k) + Get(4,ii);
							ans = max(ans, tmp);
						}
					}
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		
		if(n <= 1000){
			memset(f,0,sizeof(f));
			
			for(int i=1;i<=n;++i){
				for(int j=0;j<=i;++j){
					for(int k=0;k<=i;++k){
						if(j+k > i) continue;
						ll l = i-j-k;
						
						if(j > _n || k > _n || l > _n) continue;
						
						if(j > 0) f[j][k][l] = max(f[j][k][l], f[j-1][k][l] + A[i].a);
						if(k > 0) f[j][k][l] = max(f[j][k][l], f[j][k-1][l] + A[i].b);
						if(l > 0) f[j][k][l] = max(f[j][k][l], f[j][k][l-1] + A[i].c);
					}
				}
			}
			
			ll i = n;
			for(int j=0;j<=i;++j){
				for(int k=0;k<=i;++k){
					if(j+k > i) continue;
					ll l = i-j-k;
					if(j > _n || k > _n || l > _n) continue;
					ans = max(ans, f[j][k][l]);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		
		sort(A+1,A+1+n, cmp);
		
		memset(f,0,sizeof(f));
		ll tong[5] = {};
		for(int i=1;i<=n;++i){
			if(i <= _n) ans += A[i].a;
			else ans += A[i].b;
		}
		
		cout<<ans<<'\n';
	}
	
	
	
	
	return 0;
}
