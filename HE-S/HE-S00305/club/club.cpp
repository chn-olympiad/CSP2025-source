#include<bits/stdc++.h>
using namespace std;
int t;
int a[5][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--){
		int n,ans = 0,v1[5] = {0};
		cin >> n;
		int Max[n+5] = {0};
		int a[5][100005] = {0};
		int v[n] = {0};
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j];
			}
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				if(Max[i] < a[i][j]){
					Max[i] = a[i][j];
					v[i] = j;
				}
			}
		}
		for(int i = 1;i <= n;i++){
			if(v[i] == 1) v1[i]++;
			if(v[i] == 2) v1[i]++;
			if(v[i] == 3) v1[i]++;
		}
		for(int i = 1;i <= n;i++){
			if(v1[i] <= n/2){
				ans+=Max[i];
			}
//			cout << Max[i] << endl;
		}
		cout << ans << "\n";//我真服了 
	}//ccf能祝我过吗; 
	return 0;
}
