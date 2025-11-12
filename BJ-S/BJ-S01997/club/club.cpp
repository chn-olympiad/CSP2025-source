#include<bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 7;
#define ll long long
ll a[MX],b[MX],c[MX];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin >> T;
	while(T--){
		int n;cin >> n;
		for(int i = 1;i <= n;i++)cin >> a[i] >> b[i] >> c[i];
		vector<int > A,B,C;
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			ll mx = max(a[i],max(b[i],c[i]));
			if(mx == a[i]){ans += a[i];A.push_back(i);}
			else if(mx == b[i]){ans += b[i];B.push_back(i);}
			else{ans += c[i];C.push_back(i);}
		}
		//cerr << "cur ans = " << ans << '\n';
		if(A.size() <= n / 2 && B.size() <= n / 2 && C.size() <= n / 2)cout << ans << '\n';
		else if(A.size() > n / 2){
			//cerr << "A\n";
			sort(A.begin(),A.end(),[&](int x,int y){return a[x] - max(b[x],c[x]) < a[y] - max(b[y],c[y]);});
			for(int i = 0;i < A.size() - n / 2;i++){
				int it = A[i];
				ans -= a[it] - max(b[it],c[it]);
			}
			cout << ans << '\n';
		}
		else if(B.size() > n / 2){
			//cerr << "B\n";
			sort(B.begin(),B.end(),[&](int x,int y){return b[x] - max(a[x],c[x]) < b[y] - max(a[y],c[y]);});
			for(int i = 0;i < B.size() - n / 2;i++){
				int it = B[i];
				ans -= b[it] - max(a[it],c[it]);
			}
			cout << ans << '\n';
		}
		else{
			//cerr << "C\n";
			sort(C.begin(),C.end(),[&](int x,int y){return c[x] - max(a[x],b[x]) < c[y] - max(a[y],b[y]);});
			for(int i = 0;i < C.size() - n / 2;i++){
				int it = C[i];
				ans -= c[it] - max(a[it],b[it]);
			}
			cout << ans << '\n';
		}
	}	
	return 0;
}