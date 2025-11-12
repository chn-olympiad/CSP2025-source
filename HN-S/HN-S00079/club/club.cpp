#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll n,ans;
vector<ll> A,B,C;

void work(){
	ans = 0;
	A.clear();
	B.clear();
	C.clear();
	cin >> n;
	for(int i = 1;i <= n;i++){
		ll a,b,c;
		cin >> a >> b >> c; 
		if(a >= b && a >= c){
			A.push_back(min(a - b,a - c));
			ans += a;
		}else if(b >= a && b >= c){
			B.push_back(min(b - a,b - c));
			ans += b;
		}else if(c >= a && c >= b){
			C.push_back(min(c - a,c - b));
			ans += c;
		}else{
			cout << "ERORR\n";
			return ;
		}
	}
	if(A.size() > n / 2){
		sort(A.begin(),A.end());
		for(int i = 0;i < A.size() - n / 2;i++){
			ans -= A[i];
		}
	}
	if(B.size() > n / 2){
		sort(B.begin(),B.end());
		for(int i = 0;i < B.size() - n / 2;i++){
			ans -= B[i];
		}
	}
	if(C.size() > n / 2){
		sort(C.begin(),C.end());
		for(int i = 0;i < C.size() - n / 2;i++){
			ans -= C[i];
		}
	}
	cout << ans << "\n"; 
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll T;
	cin >> T;
	while(T--) work();
	return 0;
}
