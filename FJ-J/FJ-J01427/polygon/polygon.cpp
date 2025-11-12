#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);\
				freopen(x".out","w",stdout)
const int N = 5e3+10; 
const int mod = 998244353;
int n,a[N],b[N],sum,len,ans;
void dfs(int x){
	if(x > n){
		if(len >= 3 && sum > 2*b[len]){
			ans++;
		}
		return;
	}
	for(int i=0;i<=1;i++){
		if(i==1){
			b[++len] = a[x]; 
			sum += a[x];
			dfs(x+1);
			len--;
			sum -= a[x];
		}else{
			dfs(x+1);
		}
	}
}
int main(){
	FILE("polygon");
	cin >> n;
	if(n >= 20){
		cout << 0 << "\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dfs(1);
	cout << ans;
	return 0;
}

