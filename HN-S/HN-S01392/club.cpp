#include <bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >>t;
	while(t --){
		int n;
		cin >> n;
		int a[n]={0}, b[n]={0}, c[n]={0}, f[n][3]={0}, cnt=0, ans=0;
		for(int i = 1;i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
			if(c[i] == 0&&b[i] == c[i]) cnt ++;
		}
		if(cnt == n){
			int aa = 0;
			sort(a+1,a+n+1);
			for(int i = n/2+1;i <= n; i++) aa += a[i];
			cout << aa << "\n";
			continue;
		}
		for(int i = 1;i <= n; i++){
			f[i][0] = max(max(f[i-1][0],f[i-1][1]),f[i-1][2])+a[i];
			f[i][1] = max(max(f[i-1][0],f[i-1][1]),f[i-1][2])+b[i];
			f[i][2] = max(max(f[i-1][0],f[i-1][1]),f[i-1][2])+c[i];
		}
		ans = max(max(f[n][0], f[n][1]),f[n][2]);
		cout << ans <<"\n";
	}
	return 0;
} 
//mengCtulemengka mengCCtulemengCka dadiguayamekaodigua yikuaiqiannengmaisaer


