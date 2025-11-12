#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin >> t;
	while (t--){
		int n;cin >> n;
		if (n == 2){
			int k[10];
			for (int i = 1;i <= 6;i++)cin >> k[i];
			int MAX = 0;
			for (int i = 1;i <= 3;i++){
				for (int j = 4;j <= 6;j++){
					int sum = k[i] + k[j];
					if (i % 3 == j % 3)continue;
					if (sum > MAX)MAX = sum;
				}	
			}
			cout << MAX << endl;
		}
		else {
			int ans = 0;
			int a[1919810];
			for (int i = 1;i <= n;i_++){
				cin >> a[i];int b,c;cin >> b >> c;
			}
			sort(a+1,a+n+1,cmp);
			int l = n >> 1;
			for (int i = 1;i <= l;i++)ans += a[i];
			
			cout << ans << endl;
		}
		
	}
}
