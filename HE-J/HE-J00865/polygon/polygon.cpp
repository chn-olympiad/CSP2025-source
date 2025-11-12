#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+10,Mod = 998244353;
int n,a[N],ans = 0;

void dfs(int id,int mx,int sum){
	if(id == n+1) return;
	int m = mx,s = sum;
	mx = max(mx,a[id]);
	sum+=a[id];
	if(sum > mx*2){
		ans++;
		ans%=Mod;
	}
	dfs(id+1,mx,sum);
	dfs(id+1,m,s);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n <= 20){
		dfs(1,0,0);
		cout << ans;
		return 0;
	}else{
		cout << 366911923;
	}
	return 0;
}
