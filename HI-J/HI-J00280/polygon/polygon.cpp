#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+5;
const int MOD = 99844353;
int a[N];
long long ans;
int n;

void dfs(int num,int ii,int ma,int all){
	
	if(num >= 3){
		if(all > ma*2){
			ans++;
		}
	}
	
	for(int i = ii+1; i <= n; i++){
		int mm;
		mm = max(ma , a[i]);
		dfs(num+1,i,mm,all+a[i]);
	}
	return ;
}

int main() {
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);


	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	
	dfs(0,0,0,0);
	
	cout << ans % MOD;
	
	return 0;
}
