//m >= 3
//a[1] + a[2] + ... + a[n] > 2 * max(a[i])
//同余定理:(a * b) % c = (a % c) * (b % c) % c 
//暴力骗分(40) 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
typedef long long ll;
using namespace std;

const ll MOD = 998244353;
ll n,num;
ll a[5010],ans[5010];
bool flag[5010] = {0};

void dfs(int x,int r){//组合数枚举 
	if(x == r + 1){
		ll sum = 0,maxn = 0;
		for(int i = 1;i <= r;i++){
			sum += a[ans[i]];//总和 
			maxn = max(maxn,a[ans[i]]);//最大值 
		}
		if(r >= 3 && sum > 2 * maxn){
			//for(int i = 1;i <= r;i++) cout << a[ans[i]] << " ";
			//cout << endl;
			num++;
		}
		return ;
	}
	for(int i = ans[x - 1] + 1;i <= n;i++){
		if(flag[i] == 0){
			ans[x] = i;
			flag[i] = 1;
			dfs(x + 1,r);
			flag[i] = 0;
		}
	} 
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	
	for(int i = 3;i <= n;i++){
		dfs(1,i);
	}
	
	cout << num % MOD;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
