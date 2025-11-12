#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t;
int n;

struct node{
	long long a,b,c;
}a[N];
long long f[2][105][105]; //f[0/1][j - 1][k - 1][n - j - k + 2]
bool cmp(node a,node b){
	if(a.a == b.a){
		return a.b > b.b;
	}
	return a.a > b.a;
}
bool cmp2(node a,node b){
	if(a.a == b.a) return a.b < b.b;
	return a.a > b.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		memset(a,0,sizeof(a));
		cin >> n;
		
		bool fa = true,fb = true;
		for(int i = 1;i <= n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			if(a[i].b != 0) fa = false;
			if(a[i].c != 0) fb = false;
		}
		if(n >300){
			if(fa && fb){
				sort(a + 1,a + n + 1,cmp);
				int ans = 0;
				for(int i = 1;i <= n / 2;i++){
					ans += a[i].a;
					
				}
				cout << ans << endl;
				continue;
			}
			if(fb){
				sort(a + 1,a + n + 1,cmp2);
				int cnt1 = 0,cnt2 = 0;
				long long ans = 0;
				for(int i = 1;i <= n;i++){
					if(a[i].a > a[i].b && cnt1 < n / 2){
						cnt1++;
						ans += a[i].a;
					}
					else{
						cnt2++;
						ans += a[i].b;
					}
				}
				cout << ans << endl;
				continue;
			}
			int cnta = 0,cntb = 0,cntc = 0;
			long long ans = 0;
			for(int i = 1;i <= n;i++){
				int mx = max(a[i].a,max(a[i].b,a[i].c));
				if(mx == a[i].a){
					if(cnta <n / 2){
						cnta++;
						ans += a[i].a;
					}
					else{
						int mxx = max(a[i].b,a[i].c);
						if(mxx == a[i].b){
							cntb++;
							ans += a[i].b;
						}
						else{
							cntc++;
							ans += a[i].c;
						}
						
					}
				}
				else if(mx == a[i].b){
					if(cntb <n / 2){
						cntb++;
						ans += a[i].b;
					}
					else{
						int mxx = max(a[i].a,a[i].c);
						if(mxx == a[i].a){
							cnta++;
							ans += a[i].a;
						}
						else{
							cntc++;
							ans += a[i].c;
						}
						
					}
				}
				else{
					if(cntc <n / 2){
						cntc++;
						ans += a[i].c;
					}
					else{
						int mxx = max(a[i].a,a[i].b);
						if(mxx == a[i].a){
							cnta++;
							ans += a[i].a;
						}
						else{
							cntb++;
							ans += a[i].b;
						}
						
					}
				}
			}
			cout << ans << endl;
			continue;
		}
		
		
		
		memset(f,0,sizeof(f));
		int tmp = 0;
		
		for(int i = 1;i <= n;i++){
			long long ans = -1;
			tmp ^= 1;
			for(int j = 0;j <= min(i,n / 2);j++){
				for(int k = 0;k <= min(i,min(n / 2,i - j));k++){
					//f[tmp][j][k][i - j - k] = 0;
					if(j != 0){
						f[tmp][j][k] = max(f[tmp][j][k],f[tmp ^ 1][j - 1][k] + a[i].a);
					}
					if(k != 0){
						f[tmp][j][k]= max(f[tmp][j][k],f[tmp^1][j][k - 1] + a[i].b);
					}
					if(i - j - k != 0 && i - j - k <= n / 2){
						f[tmp][j][k] = max(f[tmp][j][k],f[tmp^1][j][k] + a[i].c);
					}
					ans = max(ans,f[tmp][j][k]);
				}
			}
			if(i == n){
				cout << ans << endl;
			}
			//cout << ans << ' ';
			
		}
//		int ans = -1;
//		for(int i = 0;i <= n / 2;i++){
//			for(int j = 0;j <= n / 2;j++){
//				ans = max(ans,f[0][i][j][n - i - j]);
//			}
//		}
//		cout << ans << endl;
	}
	return 0;
	
} 
