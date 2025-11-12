#include <bits/stdc++.h>
using namespace std;
int a[3][100005];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(NULL);
	int t, n, ans=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0;i<n;i++){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			ans+=max(max(a[0][i], a[1][i]), a[2][i]);
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
