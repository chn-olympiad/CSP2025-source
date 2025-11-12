#include<bits/stdc++.h>
using namespace std;

int a[5010];
const int N = 998344353;
long long jc(int x){
	long long cnt = 1;
	for(int i = 1; i <= x; i++)cnt = cnt*i%N;
	return cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	long long ans = 0;
	if(n <= 3){
		if(n <= 2){
			cout<<0;
			return 0;
		}
		int cnt = 0,maxn = 0;
		for(int i = 1; i <= n; i++){
			cnt += a[i];
			maxn = max(maxn,a[i]);
		}
		if(maxn*2 < cnt)
		{
			ans++;
		}
		cout<<ans;
		return 0;
	} 
	for(int i = 3; i <= n; i++){
		ans += jc(n)/(jc(i)+jc(n-i));
		ans %= N;
	}
	cout<<ans;
	return 0;
}
