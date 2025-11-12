#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10004;

int t, n, maxn;
ll ans;
struct Member{
	ll a1,a2,a3;//三个部门的满意度 
};
vector <Member> mem;//动态数组保存每个人的满意度 
ll f[N][4][N/2];//正常做法需要 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		mem.clear();
		memset(f,0,sizeof(f));
		cin >> n;
		maxn = n/2;
		ll a1,a2,a3;
		for(int i = 1; i <= n; ++i){
			cin >> a1 >> a2 >> a3;
			mem.push_back({a1,a2,a3});
		}
		////////////主程序////////////
		if(n<=500){//正常做 
			for(int i = 1; i <= maxn; ++i){
				f[1][1][i]=mem[0].a1;
				f[1][2][i]=mem[0].a2;
				f[1][3][i]=mem[0].a3;
			}
			ans=0;
			for(int i = 2; i <= n; ++i){
				for(int j = 1; j <= 3; ++j){
					for(int k = maxn; k >= 0; --k){
						ll a;
						if(j==1) a=mem[i-1].a1;
						else if(j==2) a=mem[i-1].a2;
						else a=mem[i-1].a3;
						if(k==0){
							ll t=0;
							for(int p = 1; p <= 3; ++p){
								for(int q = 0; q <= maxn; ++q){
									t = max(t,f[i-1][p][q]);
								}
							}
							f[i][j][k] = max(f[i][j][k],t);
						}else if(k<maxn){
							for(int p = 1; p <= 3; ++p){
								if(p!=j){
									f[i][j][k] = max(f[i][j][k],f[i-1][p][k+1]+a);
								}else{
									f[i][j][k] = max(f[i][j][k],f[i-1][p][maxn-k]+a);
								}
							}
						}else{
							for(int p = 1; p <= 3; ++p){
								if(p!=j){
									f[i][j][k] = max(f[i][j][k],f[i-1][p][k]+a);
								}else{
									f[i][j][k] = max(f[i][j][k],f[i-1][p][maxn-k]+a);
								}
							}
						}
					}
				}
			}
			for(int i = 1; i <= maxn; ++i){
				for(int j = 1; j <= 3; ++j){
					ans = max(ans,f[n][j][i]);
				}
			}
			cout << ans << "\n";
		}
	}
	
	return 0;
}
