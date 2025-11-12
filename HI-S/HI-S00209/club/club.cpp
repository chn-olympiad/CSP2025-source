#include<bits/stdc++.h>
template<typename T>inline T read(void){
	T x = 0;
	char ch = std::getchar();
	bool f = true;
	while(ch<'0' || ch>'9'){
		if(ch == '-') f = false;
		ch = std::getchar();
	}
	while('0'<=ch && ch<='9'){
		x = (x<<1) + (x<<3) + (ch^48);
		ch = std::getchar();
	}
	return f ? x : -x;
}
#define ll long long
#define id second
const int N = 1e5+5;
int v[N],a[N],b[N],c[N],del[N],n;
std::pair<int,int> x[N];
std::priority_queue<int> q1,q2;
namespace Code1{
	int C[5],p[5];
	ll Solve(){
		for(int i = 1;i<=3;++i) C[i] = 0;
		ll ans = 0;
		for(int i = 1;i<=n;++i){
			int tot = 0;
			int Mx = std::max({a[i],b[i],c[i]});
			if(Mx == a[i]) p[++tot] = 1;
			if(Mx == b[i]) p[++tot] = 2;
			if(Mx == c[i]) p[++tot] = 3;
			if(tot == 1) ++C[p[1]];
			ans += Mx;
		}
		int Mx = 0;
		for(int i = 1;i<=3;++i) Mx = std::max(Mx,C[i]);
		if(Mx>(n/2)) return 0;
  		return ans;
	}
}
inline ll Solve(int *A,int *B,int *C){
	for(int i = 1;i<=n;++i) v[i] = std::max(B[i],C[i]);
	for(int i = 1;i<=n;++i) del[i] = A[i] - v[i];
	for(int i = 1;i<=n;++i) x[i] = {A[i],i};
	std::sort(x+1,x+n+1);
	ll ans = 0;
	for(int i = 1;i<=(n/2);++i) ans += v[x[i].id],q1.push(del[x[i].id]);
	for(int i = (n/2)+1;i<=n;++i) ans += A[x[i].id],q2.push(-del[x[i].id]);
	while(!q1.empty() && !q2.empty()){
		int x = q1.top() + q2.top();
		q1.pop(),q2.pop();
		if(x>=0) ans += x;
	}
	return ans;
}
int main(){
	std::freopen("club.in","r",stdin);
	std::freopen("club.out","w",stdout);
	int T = read<int>();
	while(T--){
		n = read<int>();
		for(int i = 1;i<=n;++i)
			a[i] = read<int>(),b[i] = read<int>(),c[i] = read<int>();
    	ll ans = Code1::Solve();
		ans = std::max(ans,Solve(a,b,c));
		ans = std::max(ans,Solve(b,a,c));
		ans = std::max(ans,Solve(c,b,a));
		printf("%lld\n",ans);
	}
	return 0;
}

