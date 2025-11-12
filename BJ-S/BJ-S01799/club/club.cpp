#include<bits/stdc++.h>
using namespace std;
const int N =1e6 + 10;
int a[N],n,m,q,k;
int b[N],c[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <=n;i++){
			cin >> a[i] >> b[i] >> c[i];
		}
		if(n != 2){
			int ans = 0;
			sort(a + 1,a + n + 1,greater<int>());
			for(int i = 1;i <= n /2;i ++){
				ans += a[i];
			}
			cout << ans << '\n';
			
		}
		if(n == 2){
			int ans = 0;
			ans = max(max(max(a[1] + b[2],a[1] + c[2]),max(b[1] + a[2],b[1] + c[2])),max(c[1] + a[2],c[1]+b[2]));
			cout << ans << '\n';
		}
		
	}
	
	
	return 0;
}
