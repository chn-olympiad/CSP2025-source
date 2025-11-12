#include<bits/stdc++.h>
#include<cstdio>

using namespace std;

int n, m;
int a[110]; 


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int ans = 0;
	for(int i = 1;i <= n * m; i++){
		cin >> a[i];
	}
	if(n == 1 && m == 1)cout << n << m;
	else if(n == 1){
		for(int i = 2; i <= n * m; i ++){
			if(a[1] < a[i])ans ++;
		}		
		cout << n << ans + 1;
	}
	else if(m == 1){
		for(int i = 2; i <= n * m; i ++){
			if(a[1] < a[i])ans ++;
		}
		cout << ans + 1 << m;
	}
	else if(n == 2){
		for(int i = 2; i <= n * m; i ++){
			if(a[1] < a[i])ans ++;
			
		}
		if(ans < m)cout << "1" << ans + 1;
		else cout << "2" << 2 * m - ans;
	}
	else if(m == 2){
		for(int i = 2; i <= n * m; i ++){
			if(a[1] < a[i])ans ++;
			
		}
		if(ans < m)cout << ans + 1 << "1";
		else cout << 2 * m - ans << "2";
	}
	else{
		for(int i = 2; i <= n; i ++){
			if(a[1] < a[i])ans ++;
			
		}
		int l = (ans + 1)/ m;
		int b = (ans + 1) % m;
		cout << l + 1 << b;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
