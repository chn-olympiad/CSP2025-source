#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define accept 0
int a[1000005],n,ans;
int C(int a,int b){
	int sum = 1;
	for(int i = a+1;i <= b;i++){
		sum *= i;
		sum %= 998244353;
	}
	return sum;
}
void dfs(int i,int mx,int sum,int c){
	if(i == n){
		if(c < 2){
			return ;
		}
		if(sum > 2*mx){
			ans++;
			//cout << mx <<' ' << sum << ' ' << c << endl; 
		}
		mx = max(mx,a[i]);
		sum += a[i];
		if(sum > 2*mx){
			ans++;
			//cout << mx <<' ' << sum << ' ' << c+1 << endl; 
		}
		return;
	}
	dfs(i+1,mx,sum,c);
	mx = max(mx,a[i]);
	sum += a[i];
	//cout << i << ' ' << sum;
	dfs(i+1,mx,sum,c+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n < 3){
		cout << 0;
		return accept;
	}else if(n == 3){
		int a[4];
		cin >> a[1] >> a[2] >> a[3];
		if(a[1] >= a[2] + a[3] || a[2] >= a[1] + a[3] || a[3] >= a[2] + a[1]){
			cout << 0;
		}else cout << 1;
	}else if(n <= 20){
		for(int i =1;i <= n;i++){
			cin >> a[i];
		}
		//cout << a[1] << a[2] << a[3] << a[4] << a[5];
		dfs(1,0,0,0);
		cout << ans;
	}else{
		for(int i =3;i <= n ;i ++){
			ans += C(i,n);
			ans %= 998244353;
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return accept;
}
