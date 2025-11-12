#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
const int N = 1e5+10;
int T,n,a[N][4],q[N],k,tb=1,tc=1,ans,Max,f,s,t;
void dfs(int x,int step){
	if(x > n){
		if(ans > Max){
			Max = ans;
		}
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1 && f<n/2){
			ans += a[x][1];
			f++;
			dfs(x+1);
			f--;
			ans -= a[x][1];
		}else if(i==2 && s<n/2){
			ans += a[x][2];
			s++;
			dfs(x+1);
			s--;
			ans -= a[x][2];
		}else if(t<n/2){
			ans += a[x][3];
			t++;
			dfs(x+1);
			t--;
			ans -= a[x][3];
		}
	}
}
int main(){
	FILE("club");
	cin >> T;
	while(T--){
		cin >> n;
		tb=1,tc=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a[i][j];
				if(j != 1 && a[i][j] != 0){
					tb=0;
					if(j==3){
						tc=0;
					}	
				}
			}
		}
		if(n<=10){
			ans=0,Max=0,f=0,s=0,t=0;
			dfs(1,3);
			cout << Max << "\n";
			continue;
		}
		if(tb == 1){
			for(int i=1;i<=n;i++){
				q[i] = a[i][1];
			}
			sort(q+1,q+n+1);
			int ans=0;
			for(int i=n;i>=n/2+1;i--){
				ans += q[i];
			}
			cout << ans << "\n";
			continue;
		}
		ans=0,f=0,s=0,t=0;
		for(int i=1;i<=n;i++){
			int tmp[4] = {0,a[i][1],a[i][2],a[i][3]};
			sort(tmp+1,tmp+4);
			for(int i=3;i>=1;i--){
				if(tmp[i] == a[i][1] && f < n/2){
					f++;
					ans += tmp[i];
					break;
				}else if(tmp[i] == a[i][2] && s < n/2){
					s++;
					ans += tmp[i];
					break;
				}else if(tmp[i] == a[i][3] && t < n/2){
					t++;
					ans += tmp[i];
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
