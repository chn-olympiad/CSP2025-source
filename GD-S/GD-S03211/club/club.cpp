#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define lnf 0x3f3f3f3f
const int maxn = 1e7 + 10;
int a[maxn][4];
int t,n;
ll ans = 0;
void k(){
	int len = n/2;
	int id1,id2,max1,max2; 
	for(int i = 0;i <= len;i++){
		if(a[2*len][1] > a[2 *len][2]){
			id1 = 1;max1 = a[2*len][1];
			if(a[2*len][1] > a[2*len][3]);
			else id1 = 3;max1 = a[2*len][3];
		}else{
			id1 = 2;max1 = a[2*len][2];
			if(a[2*len][2] > a[2*len][3]);
			else id1 = 3;max1 = a[2*len][3];
		}
		 
	}
}
void c(){
	for(int i = 0;i < n;i++){
		ans += max(max(a[i][1],a[i][2]),a[i][3]);
	}
	cout << ans << "\n";
}									

void m(){
	bool A = 1,B = 1;
	for(int i = 0;i < n;i++){
		if(a[i][3] != 0){
			A = 0;B = 0;
			break;
		}
	}
	if(B==1){
		for(int i = 0;i < n;i++){
			for(int j = 2;j <= 3;j++){
				if(a[i][j] != 0){
					A = 0;break;
				}
			}
		}
		
		if(A == 1){
//			cout << "A!B!\n";
			static int b[maxn];
			for(int i = 0;i < n;i++){
				b[i] = a[i][1];
			}
			sort(b,b+n);
			for(int i = n/2;i < n;i++){
				ans+=b[i];
			}
			
			cout << ans << "\n";
			return;
		}else{
//			cout << "B!\n";
			c();return;
		}
	}
//	cout << "\n";
	c();
	
}
int main(){
//	freopen("club.in","in",std);

	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		for(int i = 0;i < n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j];
			}
		}
//		k();
//		cout << ans << "\n";
		m();
//		for(int i = 0;i < n;i++){
//			for(int j = 1;j <= 3;j++){
//				f[i][j] = max(f[i-1][1],f[i-1][2],f[i-1][3]) + a[i][j];
//			}
//		}

	}
}
