#include<bits/stdc++.h>
using namespace std;
const int M = 100010;
int t,n,a[M][4],nummax,ans;
void dfs(int numa,int numb,int numc,int id,int tot){
	if(id == n+1){
		ans = max(ans,tot);
		return;
	}
	if(numa < n/2) dfs(numa+1,numb,numc,id+1,tot+a[id][1]);
	if(numb < n/2) dfs(numa,numb+1,numc,id+1,tot+a[id][2]);
	if(numc < n/2) dfs(numa,numb,numc+1,id+1,tot+a[id][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		memset(a,0,sizeof(a));
		nummax = 0;ans = 0;
		cin >> n;  nummax = n/2;
		bool p1 = true,p2 = true; // p1 teA  p2 teB
		for(int i = 1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][3] != 0 && a[i][2] != 0) p1 = false;
			if(a[i][3] != 0) p2 = false;
		}
		if(n == 2){
			ans = -1;
			for(int i = 1;i<=3;i++){
				for(int j = 1;j<=3;j++){
					if(i == j) continue;
					ans = max(ans,a[1][i]+a[2][j]);
				}
			}
			cout << ans << endl;
		}
		if(n <= 10 && n > 2){
			dfs(0,0,0,1,0);
			cout << ans << endl;
		}
		if(n>200 && p1){
			int aa[M] = {0};
			for(int i = 1;i<=n;i++) aa[i] = a[i][1];
			sort(aa+1,aa+n+1);
			for(int i = n;i>=n/2;i--) ans+=aa[i];
			cout << ans << endl; 
		}
		/*else if(n>=200 && p2){
			
		}*/
	}
	return 0; 
}
