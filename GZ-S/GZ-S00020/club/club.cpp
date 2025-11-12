//GZ-S00020 修文中学 伍震新
#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int a[maxn][3];
int t_mx;
void dp(int n,int mx,int q,int* f){
	for(int i = 0;i<3;i++){
		if(f[i] > n/2){
			return;
		}
	}
	if(mx > t_mx){
		t_mx = mx;
	}
	if(q==n) return;
	for(int i = 0;i<3;i++){
		// cout << q << " " << i << endl;
		mx+=a[q][i];
		f[i]++;
		dp(n,mx,q + 1,f);
		f[i]--;
		mx-=a[q][i];
	}
	return;
}
void slove(){
	int n;
	int f[3];
	for(int i = 0;i < 3;i++){
		f[i] = 0;
	}
	cin >> n;
	for(int i = 0;i < n;i++){
		int mx = -1, p = 0;
		for(int j = 0;j < 3;j++){
			cin >> a[i][j];
			if(a[i][j] > mx){
				p = j;
				mx = a[i][j];
			}
		}
		f[p]++;
	}
	int mx = f[0],p = 0;
	for(int i = 1;i < 3;i++){
		if(f[i] > mx){
			p = i;
			mx = f[i];
		}
	}
	int ans = 0;
	if(f[p] <= n/2){
		for(int i = 0;i<n;i++){
			int mx = -1;
			for(int j = 0;j<3;j++){
				mx = max(a[i][j],mx);
			}
			ans+=mx;
		}
		cout << ans << endl;
	} 
	else{
		int f[3] = {0,0,0};
		t_mx = 0;
		dp(n, 0, 0, f);
		cout << t_mx << endl;
	}
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--) slove();

	return 0;
} 
