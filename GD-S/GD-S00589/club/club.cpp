#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],g[N],b[N],d[5],ans,m[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		ans = 0;
		memset(g,0,sizeof(g));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		memset(m,0x3f,sizeof(m));
		cin >> n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
				if(a[i][j]>=a[i][g[i]])
					g[i] = j;
			}
			for(int j=1;j<=3;j++){ 
				if(a[i][j]>a[i][b[i]] && j!=g[i])
					b[i] = j;
			}
			d[g[i]]++;
			ans += a[i][g[i]];
		}
		for(int j=1;j<=3;j++){
			if(d[j]>n/2){
				for(int i=1;i<=n;i++){
					if(g[i]==j){
						m[i] = a[i][g[i]]-a[i][b[i]];
					}
				}
				sort(m+1,m+n+1);
				for(int i=1;i<=d[j]-n/2;i++){
					ans -= m[i];
				}
				break;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
